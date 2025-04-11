#ifndef TEST_RCPP_H
#define TEST_RCPP_H

#include <Rcpp.h>

#include <random>
#include <algorithm>
#include <iterator>

using namespace Rcpp;

namespace Random {
    // Generic function using a provided engine
    template <typename ContainerType, typename Engine>
    ContainerType generate_random_sequence(std::size_t length, Engine engine = Engine()) {
        using T = typename std::remove_reference<typename ContainerType::value_type>::type;
        ContainerType sequence(length);
        std::uniform_real_distribution<T> dist;
        std::generate(sequence.begin(), sequence.end(), [&]() { return dist(engine); });
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

    template <class T> T Rminstd_rand0(std::size_t length) {
        std::minstd_rand0 engine;
        return generate_random_sequence<T>(length, engine);
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

    // mt19937_64
    template <class T> T Rmt19937_64(std::size_t length) {
        std::mt19937_64 engine;
        return generate_random_sequence<T>(length, engine);
    }

    // ranlux24_base
    template <class T> T Rranlux24_base(std::size_t length) {
        std::ranlux24_base engine;
        return generate_random_sequence<T>(length, engine);
    }

    // ranlux48_base
    template <class T> T Rranlux48_base(std::size_t length) {
        std::ranlux48_base engine;
        return generate_random_sequence<T>(length, engine);
    }

    // ranlux24
    template <class T> T Rranlux24(std::size_t length) {
        std::ranlux24 engine;
        return generate_random_sequence<T>(length, engine);
    }

    // ranlux48
    template <class T> T Rranlux48(std::size_t length) {
        std::ranlux48 engine;
        return generate_random_sequence<T>(length, engine);
    }

    // knuth_b
    template <class T> T Rknuth_b(std::size_t length) {
        std::knuth_b engine;
        return generate_random_sequence<T>(length, engine);
    }

    // default_random_engine
    template <class T> T Rdefault_random_engine(std::size_t length) {
        std::default_random_engine engine;
        return generate_random_sequence<T>(length, engine);
    }

    // subtract_with_carry_engine
    template <class T> T Rsubtract_with_carry_engine(std::size_t length) {
        std::subtract_with_carry_engine<unsigned int, 24, 10, 24> engine;
        return generate_random_sequence<T>(length, engine);
    }

    // subtract_with_carry_engine_64
    template <class T> T Rsubtract_with_carry_engine_64(std::size_t length) {
        std::subtract_with_carry_engine<uint64_t, 48, 5, 24> engine;
        return generate_random_sequence<T>(length, engine);
    }
}

#endif