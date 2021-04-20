#include <iostream>
#include <vector>
#include <stack>



class STree {
public:
    void push(int rhs) {
        std::ptrdiff_t k = 0;
		while (data[k].count) {
			if (rhs < data[k].value) {
				k = 2 * k + 1;
			}
			else if (rhs == data[k].value) {
				break;
			}
			else {
				k = 2 * k + 2;
			}

		}
		data[k].count += 1;
		data[k].value = rhs;
    }

	void writeTo() {

	}


private:
    struct Node {
        int value = 0;
        int count = 0;
    };
    std::vector<Node> data = std::vector<Node>(100);
};

int main()
{
	STree a;
	a.push(9);
	a.push(89);
	a.push(78);
}

