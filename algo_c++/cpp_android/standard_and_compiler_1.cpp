class Test {
private:
	Test(const Test&) {}
public:
	Test(int n) {}
};

int main() {
	Test t = 1;
}