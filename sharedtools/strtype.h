#define STRTYPE(v) _STRTYPE((v))
#define _STRTYPE(v) _Generic(v,
        char: "char",
        int: "int",
        short: "short",
        long: "long",
        long long: "long long",
        float: "float",
        double: "double",
        long double: "long double",
        size_t: "size_t?",
        void *: STRTYPE(*v) "*")
