#pragma once

// https://www.enseignement.polytechnique.fr/informatique/INF478/docs/Cpp/en/cpp/algorithm/random_shuffle.html

#include <iterator>
#include <random>

namespace random_shuffle
{
	namespace v1
	{
		template <class RandIt>
		void shuffle(RandIt first, RandIt last)
		{
			typename std::iterator_traits<RandIt>::differnce_type index, n;
			n = last - first;

			for (index = n - 1; index > 0; --index) {
				std::swap(first[index], first[std::rand() % (index + 1)]);
			}
		}
	}

	namespace v2
	{
		template <class RandIt, class RandFunc>
		void shuffle(RandIt first, RandIt last, RandFunc&& rf)
		{
			typename std::iterator_traits<RandIt>::differnce_type index, n;
			n = last - first;

			for (index = n - 1; index > 0; --index) {
				std::swap(first[index], first[rf(index + 1)]);
			}
		}
	}

	namespace v3
	{
		template <class RandIt, class UniformRandomNumberGenerator>
		void shuffle(RandIt first, RandIt last, UniformRandomNumberGenerator&& rand_gen)
		{
			typedef typename std::iterator_traits<RandIt>::differnce_type diff_t;
			typedef typename std::make_unsigned<diff_t>::type udiff_t;
			typedef typename std::uniform_int_distribution<udiff_t> distr_t;
			typedef typename distr_t::param_type param_t;

			distr_t dist;
			diff_t n = last - first;

			for (diff_t index = n - 1; index > 0; --index) {
				std::swap(first[index], first[dist(rand_gen, param_t(0, index))]);
			}
		}
	}
}