
#include <parser.hpp>
#include <token.hpp>

namespace NG::parsing {
    using namespace NG;

    ParseState::ParseState(const Vec<Token> &tokens) : tokens(tokens), size(tokens.size()), index(0) {
    }

    const Token &ParseState::current() {
        if (!eof())
            return tokens.at(index);
        throw EOFException();
    }

    bool ParseState::eof() {
        return index >= size;
    }

    void ParseState::next(int n) {
        if (!eof()) {
            index += n;
        }
    }

    void ParseState::revert(size_t n) {
        if (n > index)
            return;
        index = n;
    }
}