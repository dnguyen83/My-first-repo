#pragma once
#include <memory>
#include <iostream>
#include <vector>
#include <string>

class object_t {
public:

	template<typename T>
	object_t(T x)
		: self_(std::make_shared<model<T>>(std::move(x)))
	{}

	void draw(std::ostream& out, size_t position) const {
		self_->draw_(out, position);
	}

private:
	struct concept_t {
		virtual ~concept_t() = default;
		virtual void draw_(std::ostream&, size_t) const = 0;
	};

	template <typename T>
	struct model : concept_t {
		model(T x)
		: data_(std::move(x))
		{}

		void draw_(std::ostream& out, size_t position) const {
			data_.draw(out, position);
		}

		T data_;
	};

	std::shared_ptr<const concept_t> self_;
};

using document_t = std::vector<object_t>;

void draw(const document_t& x, std::ostream& out, size_t position) {
	out << std::string(position, ' ') << "<document>" << std::endl;
	for (const auto& iter : x) {
		iter.draw(out, position + 2);
	}

	out << std::string(position, ' ') << "</document>" << std::endl;
}

/*in main.h


class my_class_t {
public:
void draw(std::ostream& out, size_t position) const {
out << std::string(position, ' ') << "my_class_t" << std::endl;
}
};

class your_class_t {
public:
void draw(std::ostream& out, size_t position) const {
out << std::string(position, ' ') << "your_class_t" << std::endl;
}
};

int main() {
document_t document;
document.emplace_back(my_class_t());
document.emplace_back(your_class_t());
draw(document, std::cout, 0);
return 0;
}

*/