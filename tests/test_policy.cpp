#include "policy.hpp"
#include <cassert>

int main() {
    Signal signal_case_1{75, 74, 16, 25, 8};
    assert(score_signal(signal_case_1) == 108);
    assert(classify_signal(signal_case_1) == "review");
    Signal signal_case_2{82, 101, 14, 16, 5};
    assert(score_signal(signal_case_2) == 175);
    assert(classify_signal(signal_case_2) == "review");
    Signal signal_case_3{66, 100, 8, 7, 7};
    assert(score_signal(signal_case_3) == 214);
    assert(classify_signal(signal_case_3) == "accept");
}
