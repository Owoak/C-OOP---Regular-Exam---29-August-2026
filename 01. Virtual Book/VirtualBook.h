#pragma once
#include "VirtualPage.h"
#include <vector>

class VirtualBook final {
private:
	std::vector<VirtualPage> book;

public:
	VirtualBook() = default;
	void addPage(const VirtualPage& page) {
		book.push_back(page);
	}
	void printContent() const {
		if (book.empty()) {
			return;
		}
		for (const auto& page : book) {
			page.printContent();
		}
	}
	void removeLastPage() {
		if (book.empty()) {
			return;
		}
		book.pop_back();
	}
	void removeAllPages() {
		if (book.empty()) {
			return;
		}
		book.clear();
	}
};