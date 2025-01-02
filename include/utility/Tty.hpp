//
// Created by CanhDo on 2025/01/02.
//

#ifndef QRAT_TTY_HPP
#define QRAT_TTY_HPP

#include <iostream>

class Tty {
public:
    enum Attribute {
        RESET,
        BRIGHT,
        DIM,
        UNDERLINE,
        BLINK,
        REVERSE,
        HIDDEN,

        BLACK,
        RED,
        GREEN,
        YELLOW,
        BLUE,
        MAGENTA,
        CYAN,
        WHITE,

        BKGD_BLACK,
        BKGD_RED,
        BKGD_GREEN,
        BKGD_YELLOW,
        BKGD_BLUE,
        BKGD_MAGENTA,
        BKGD_CYAN,
        BKGD_WHITE
    };

    Tty(Attribute attr);

    static void setEscapeSequencesAllowed(bool flag);

    const char *ctrlSequence() const;

private:
    static const char *const ansiCode[];
    static bool allowedFlag;

    const Attribute attr;
};

inline Tty::Tty(Attribute attr) : attr(attr) {
}

inline void Tty::setEscapeSequencesAllowed(bool flag) {
    allowedFlag = flag;
}

inline std::ostream &operator<<(std::ostream &s, const Tty &t) {
    s << t.ctrlSequence();
    return s;
}

#endif//QRAT_TTY_HPP
