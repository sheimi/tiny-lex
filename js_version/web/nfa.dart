
class NFAState {
  int id;
  int flag;
  int c;
  List<NFAState> outs;
  List<NFAState> all;

  NFAState(List<NFAState> all, int c, [Iterable<NFAState> outs]) {
    this.all = all;
    this.outs = outs == null? [] : new List<NFAState>.from(outs);
    this.outs.length = 2;
    this.c = c;
    this.id = all.length;
    all.addLast(this);
  }
}

class NFASegment {
  NFAState start;
  /* the structure is
   *  out [NFAState, index]
   */
  List outs;

  NFASegment(NFAState start,
             List out1, 
             [List out2]) {
    outs = [];
    this.start = start;
    outs.addLast(out1);
    if (out2 != null) {
      outs.addLast(out2);
    }
  }
  connect_state(NFAState state) {
    outs.forEach((item) {
      var nstate = item[0];
      var index = item[1];
      nstate.outs[index] = state;
    });
  }
}

class NFA {

  static final int END        = 0;
  static final int LAMBDA     = -1;
  static final int CAT        = -2;   // '.'
  static final int OR         = -3;   // '|'
  static final int PLUS       = -4;   // '+'
  static final int STAR       = -5;   // '*'
  static final int LEFT_PTH   = -6;   // '('
  static final int RIGHT_PTH  = -7;   // ')'
  static final int QUEST      = -8;   // '?'
  static final int LEFT_BCT   = -9;   // '['
  static final int RIGHT_BCT  = -10;  // ']'
  static final int HYPHEN = -11;      // '-'
  NFAState start;


  NFA(String regex) {
    var parsed = pre_parse(regex);
    var postfix = reg2post(parsed);
    var nseg_stack = <NFASegment>[];
    var all_states = <NFAState>[];

    pop() => nseg_stack.removeLast();
    push(s, o1, [o2]) => nseg_stack.addLast(new NFASegment(s, o1, o2));
    push_simple(s, o) => nseg_stack.addLast(new NFASegment(s, [o, 0], [o, 1]));

    postfix.forEach((item) {
      switch (item) {
        case CAT:
          var sf2 = pop();
          var sf1 = pop();
          sf1.connect_state(sf2.start); 
          push_simple(sf1.start, sf2);
          break;
        case OR:
          var sf2 = pop();
          var sf1 = pop();
          var state1 = new NFAState(all_states, LAMBDA, [sf1.start, sf2.start]);
          var state2 = new NFAState(all_states, LAMBDA);
          sf1.connect_state(state2);
          sf2.connect_state(state2);
          push_simple(state1, state2);
          break;
        case QUEST:
          var sf = pop();
          var state = new NFAState(all_states, LAMBDA, [sf.start]);
          push(state, sf.outs[0], [state, 0]);
          break;
        case STAR:
          var sf = pop();
          var state = new NFAState(all_states, LAMBDA, [sf.start]);
          sf.connect_state(state);
          push(state, [state, 1]);
          break;
        case PLUS:
          var sf = pop();
          var state = new NFAState(all_states, LAMBDA, [sf.start]);
          sf.connect_state(state);
          push(sf1.start, [state, 1]);
          break;
        default:
          var state = new NFAState(all_states, item);
          push_simple(state, state);
          break;
      }
    });
    var sf = pop();
    var state = new NFAState(all_states, END);
    sf.connect_state(state);
    this.start = sf.start;
    assert(nseg_stack.isEmpty());
    all_states.forEach((item) {
      item.flag = 0;
      print(item.id);
      print(item.c);
      item.outs.forEach((item) {
        if (item != null) {
          print(item.id);
        }
      });
      print(' ');
    });
    print_state(state) {
      if (state.flag == 1)
        return;
      state.flag = 1;
      print(state.id);
      print(state.c);
      state.outs.forEach((item) {
        if (item != null) {
          print_state(item);
        }
      });
    }
    print_state(start);
  }

  static List<int> reg2post(List<int> reg) {
    // add dot to the reg string
    var result = <int>[];
    bool first = true, add = false;
    reg.forEach((item) {
      if (add && !first
          && item != RIGHT_PTH
          && item != OR 
          && item != STAR
          && item != PLUS
          && item != QUEST) 
        result.add(CAT);
      result.add(item);
      add = true;
      add = item == OR ? false: add;
      first = false;
      first = item == LEFT_PTH ? true : first;
    });
    var sb = <int>[];
    var symbol_stack = <int>[];

    pop_symbol() {
      if ((symbol_stack.length != 0)
          && (symbol_stack.last() != LEFT_PTH))
        sb.add(symbol_stack.removeLast());
    }
    result.forEach((item) {
      switch (item) {
        case RIGHT_PTH:
          pop_symbol();
          while (symbol_stack.last() != LEFT_PTH) {
            sb.add(symbol_stack.removeLast());
          }
          symbol_stack.removeLast();
          break;
        case PLUS:
        case STAR:
          sb.add(item);
          pop_symbol();
          break;
        case CAT:
        case OR:
          pop_symbol();
          symbol_stack.addLast(item);
          break;
        case LEFT_PTH:
          symbol_stack.addLast(item);
          break;
        default:
          sb.add(item);
          break;
      }
    });
    pop_symbol();
    return sb;
  }

  static List<int> pre_parse(String regex) {
    var escape = false;
    var escape_free = <int>[];
    var regex_chars = regex.splitChars();
    regex_chars.forEach((item) {
      push(i) => escape_free.addLast(i);
      c_code(c) => c.charCodeAt(0);
      push_c(c) => push(c_code(c))
      if (escape) {
        switch(item) {
          case 'n':
            push_c('\n');
            break;
          case 'r':
            push_c('\r');
            break;
          case 's':
            push_c(' ');
            break;
          default:
            push_c(item);
            break;
        }
        escape = false;
      } else {
        switch(item) {
          case '\\':
            escape = true;
            break;
          case '+':
            push(PLUS);
            break;
          case '*':
            push(STAR);
            break;
          case '|':
            push(OR);
            break;
          case '.':
            push(CAT);
            break;
          case '?':
            push(QUEST);
            break;
          case '(':
            push(LEFT_PTH);
            break;
          case ')':
            push(RIGHT_PTH);
            break;
          case '[':
            push(LEFT_BCT);
            break;
          case ']':
            push(RIGHT_BCT);
            break;
          case '-':
            push(HYPHEN);
            break;
         default:
            push_c(item);
            break;
        }
      }
    });

    var bracket = false;
    var hyphen = false;
    int last_char;
    var result = <int>[];
    
    escape_free.forEach((item) {
      push(i) => result.addLast(i); 
      pop() => result.removeLast(); 
      if (bracket) {
        switch(item) {
          case HYPHEN:
            hyphen = true;
            break;
          case RIGHT_BCT:
            bracket = false;
            pop();
            push(RIGHT_PTH);
            break;
          default:
            if (hyphen) {
              hyphen = false;
              for (int i = last_char + 1; i != item;
                    last_char < item ? i++ : i--) {
                push(i);
                push(OR);
              }
            } else {
              last_char = item;
            }
            push(item);
            push(OR);
            break;
        }
      } else {
        switch(item) {
          case LEFT_BCT:
            push(LEFT_PTH);
            bracket = true;
            break;
          default:
            push(item);
            break;
        }
      }
    });
    return result;
  }
}
