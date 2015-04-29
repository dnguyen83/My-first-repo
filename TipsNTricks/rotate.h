#pragma once

template <typename I>
auto Slide(I f, I l, I p) -> pair<I, I>
{
	if (p < f) return{ p, rotate(p, f, l) };
	if (l < p) return{ rotate(f, l, p), p };
	return{ f, l };
}