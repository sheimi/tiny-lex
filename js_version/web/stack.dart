class Stack<E> {
  List<E> mine;
  Stack() {
    mine = new List<E>();
  }
  Stack.from(Iterable<E> other) {
    mine = List<E>.from(other);
  }
  Stack.fromList(List<E> list) {
    mine = list;
  }

  bool isEmpty() => mine.isEmpty();
  push(E value) => mine.addLast(value);
  E pop() => mine.removeLast();

}
