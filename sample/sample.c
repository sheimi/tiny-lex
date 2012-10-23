struct complex {
    float real;
    float image;
};

typedef struct complex complex_t;

int main(int argc, char** argv)
{
    int N = 10;
    complex_t cs[N];
    int i;
    for(i = 0;i < N;i++) {
        if(i % 2 == 0) {
            cs[i].real = i;
            cs[i].image = i+1;
        } else {
            cs[i].image = i;
            cs[i].real = i+1;
        }
    }
}
