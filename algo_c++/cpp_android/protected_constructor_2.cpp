// Protected ������ : �ڽ��� ���� �� ������(�߻��� ����) �ڽ��� ���� �� �ְ� �ϴ� ������ ���
class Animal {
protected:
	Animal() {}
};

class Dog : public Animal {
};

int main() {
//	Animal a;	// error. protected ������
	Dog d;
}
