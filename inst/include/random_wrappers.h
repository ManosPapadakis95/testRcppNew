#ifndef TEST_RCPP_H
#define TEST_RCPP_H

#include <random>
#include <algorithm>
#include <iterator>

#include <Rcpp/Lighter>

using namespace Rcpp;

namespace Random {
    // Generic function using a provided engine
    template <typename ContainerType, typename Engine>
    ContainerType generate_random_sequence(std::size_t length, Engine engine = Engine()) {
        using T = typename std::remove_reference<typename ContainerType::value_type>::type;
        ContainerType sequence(length);
        if constexpr (std::is_integral<typename ContainerType::value_type>::value) {
            std::uniform_int_distribution<T> dist;
            std::generate(sequence.begin(), sequence.end(), [&]() { return dist(engine); });
        } else if constexpr (std::is_floating_point<typename ContainerType::value_type>::value) {
            std::uniform_real_distribution<T> dist;
            std::generate(sequence.begin(), sequence.end(), [&]() { return dist(engine); });
        }
        return sequence;
    }
    
    template <typename ContainerType>
    ContainerType sample(ContainerType input, std::size_t size, bool replace = false) {
        ContainerType result(size);

        std::random_device rd;
        std::mt19937 engine(rd());

        if (replace) {
            // Sampling with replacement
            std::uniform_int_distribution<std::size_t> dist(0, input.size() - 1);
            for (std::size_t i = 0; i < size; ++i) {
                result[i] = input[dist(engine)];
            }
        } else {
            // Sampling without replacement (using shuffle)
            result = input;  // Copy input
            std::shuffle(result.begin(), result.end(), engine);
        }

        return result;
    }

    // minstd_rand
    template <class T> T Rminstd_rand(std::size_t length) {
        std::minstd_rand engine;
        return generate_random_sequence<T>(length, engine);
    }

    // mt19937
    template <class T> T Rmt19937(std::size_t length) {
        std::mt19937 engine;
        return generate_random_sequence<T>(length, engine);
    }

    // knuth_b
    template <class T> T Rknuth_b(std::size_t length) {
        std::knuth_b engine;
        return generate_random_sequence<T>(length, engine);
    }
}

#endif
