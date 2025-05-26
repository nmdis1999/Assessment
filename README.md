# URI Parser (STL-only)

This project implements a URI parser compliant with [RFC 3986](https://tools.ietf.org/html/rfc3986), using only the C++ Standard Library (C++20).

---

## 📁 Files

- `uri_parser.hpp` – URI struct and function declarations
- `uri_parser.cpp` – URI parsing and printing logic
- `main.cpp` – CLI for parsing user input
- `test.cpp` – Unit tests using `assert`

---

## 🛠 Build and Run

### Compile Main Program

```bash
make
./uri "http://user@host.com:8080/path?q=1#frag"
```

or interactively:

```
./uri
<type URI and press enter>
```

## Run Tests

```
make test
```

You should see:

```
All tests passed.
```
