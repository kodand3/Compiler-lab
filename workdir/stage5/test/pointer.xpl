decl
    int t, bar(str *f), foo(int *c, int *d, str *f);
enddecl

int bar(str *f) {
    begin
    *f = "hello";
    return 1;
    end
}

int foo(int *c, int *d, str *f) {
    begin
    write(*c);
    write(*d);
    t = bar(f);

    return 1;
    end
}

int main() {
    decl
        int a, b;
        int *c, *d;
        str e, *f;
    enddecl

    begin
    a = 5;
    b = 3;
    t = foo(&a, &a + 1, &e);
    write(e);
    return 1;
    end
}