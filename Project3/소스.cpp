#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

class Game {
private:
	double energy = 100;
	static int life;

public:
	double Damage();
	int IsDie();
	double ReturnEnergy();
	int ReturnLife();
};
int Game::life = 10;

double Game::Damage() {
	double damaged = 0;

	if (energy > 0) {
		damaged += rand() % 100;
		energy -= damaged;
		cout << "�������� " << damaged << " �����Ͽ� " << energy << " �� �Ǿ����ϴ�.\n";
		if (energy < 0) {
			life--;
			energy = 100;
			cout << "������ 1 �����Ͽ� " << life << "�� �Ǿ����ϴ�." << endl << endl;

		}
	}
	return energy;
}

int Game::IsDie(){
	return life > 0;
}

int Game::ReturnLife()
{
	return life;
}

double Game::ReturnEnergy()
{
	return energy;
}

void RCP();

int main(void)
{
	srand(time(NULL));

	char n;
	cout << "-------------------------------------------------------";
	cout << endl << "			���� ���� �� ����" << endl;
	cout << "-------------------------------------------------------";
	cout << endl << "�����Ͻ÷��� �ƹ�Ű�� �����ּ��� : ";
	cin >> n;
	system("cls");

	RCP();
}

void RCP()
{
	Game p1;

	while (p1.IsDie())
	{
		int choice;
		int win = 0;
		cout <<  "���� ����� ä�� : " << p1.ReturnEnergy() << " | ���� ����� ��� : " << p1.ReturnLife() << " | ���� ����� �¸� Ƚ�� : " << win << endl << endl;
		cout << "����� ���� (0�� ����, 1�� ����, 2�� ��) : ";
		cin >> choice;

		int n = rand() % 3;
		
		cout << endl << "������Դϴ�." << endl;
		Sleep(5000);

		cout << endl;

		if (choice == n)
		{
			cout << endl << "����� �̰���ϴ�.";
		}
		else
		{
			cout << endl << "����� �����ϴ�. energy�� ���Դϴ�.";
			p1.Damage();
		}

		Sleep(3000);
		system("cls");
	}

	system("cls");
	cout << "GAME OVER!!";
}