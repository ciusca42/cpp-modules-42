#ifndef SPAN_HPP
# define SPAN_HPP

class Span {
	public:
		Span();
		~Span();
		Span(const Span & obj);
		Span & operator=(const Span & obj);
};

#endif