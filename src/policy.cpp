#include "policy.hpp"

namespace {
constexpr int threshold = 178;
constexpr int risk_penalty = 4;
constexpr int latency_penalty = 4;
constexpr int weight_bonus = 6;
}

int score_signal(const Signal& signal) {
    return signal.demand * 2 + signal.capacity + signal.weight * weight_bonus
        - signal.latency * latency_penalty - signal.risk * risk_penalty;
}

std::string classify_signal(const Signal& signal) {
    return score_signal(signal) >= threshold ? "accept" : "review";
}
