#include<iostream>


class MnList {
public:
	MnList() = default;
	~MnList() noexcept;

	bool is_empty() const noexcept;
	bool is_inside(int rhs) const noexcept;
	void pop(int rhs) noexcept(false);
	void push(const int& rhs) noexcept;
	void writeAll();

private:
	struct Node {
		Node* next{ nullptr };
		int value = 0;
	};
	Node* head_{ nullptr };
};

int main()
{
	MnList a;
	std::cout << a.is_empty() << '\n';
	a.push(9);
	a.push(10);
	a.push(456);
	a.writeAll();
	std::cout << '\n';
	std::cout << a.is_empty() << '\n';
	std::cout << a.is_inside(10);
	a.pop(10);
	std::cout << a.is_inside(10);
	a.pop(10);
	a.pop(10);
	std::cout << a.is_inside(10);
	std::cout << a.is_inside(10);
}

MnList::~MnList() noexcept {
	if (is_empty()) {
		return;
	}
	while (head_ != nullptr) {
		Node* new_head = head_->next;
		delete head_;
		head_ = new_head;
	}
}

bool MnList::is_empty()const noexcept {
	return (head_ == nullptr);
}

void MnList::pop(int rhs) noexcept(false) {
	if (is_empty()) {
		std::cout << "Stack is empty!";
		return;
	}
	Node *cur_el = head_;
	if (cur_el->value == rhs) {
		Node* new_head = head_->next;
		delete head_;
		head_ = new_head;
		return;
	}
	while (cur_el->next != nullptr) {
		if (cur_el->next->value == rhs) {
			Node* next_next_point = cur_el->next->next;
			delete cur_el->next;
			cur_el->next = next_next_point;
			return;
		}
	}
}

void MnList::push(const int& rhs) noexcept {
	if (is_inside(rhs)) {
		return;
	}
	Node* old_head = head_;
	head_ = new Node;
	head_->next = old_head;
	head_->value = rhs;
}

bool MnList::is_inside(int rhs) const noexcept {
	Node *cur_el = head_;
	while (cur_el != nullptr) {
		if (cur_el->value == rhs) {
			return true;
			break;
		}
		cur_el = cur_el->next;
	}
	return false;
}

void MnList::writeAll() {
	Node *cur_el = head_;
	while (cur_el != nullptr) {
		std::cout << cur_el->value << ' ';
		cur_el = cur_el->next;
	}
}