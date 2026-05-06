#include "domain_review.hpp"
#include <cassert>

int main() {
    DomainReview item{46, 21, 22, 60};
    assert(domain_review_score(item) == 107);
    assert(domain_review_lane(item) == "watch");
}
