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
		cout << "에너지가 " << damaged << " 감소하여 " << energy << " 이 되었습니다.\n";
		if (energy < 0) {
			life--;
			energy = 100;
			cout << "생명이 1 감소하여 " << life << "이 되었습니다." << endl << endl;

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
	cout << endl << "			가위 바위 보 게임" << endl;
	cout << "-------------------------------------------------------";
	cout << endl << "시작하시려면 아무키나 눌러주세요 : ";
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
		cout <<  "현재 당신의 채력 : " << p1.ReturnEnergy() << " | 현재 당신의 목숨 : " << p1.ReturnLife() << " | 현재 당신의 승리 횟수 : " << win << endl << endl;
		cout << "당신의 선택 (0은 가위, 1은 바위, 2는 보) : ";
		cin >> choice;

		int n = rand() % 3;
		
		cout << endl << "계산중입니다." << endl;
		Sleep(5000);

		cout << endl;

		if (choice == n)
		{
			cout << endl << "당신이 이겼습니다.";
		}
		else
		{
			cout << endl << "당신이 졌습니다. energy가 깎입니다.";
			p1.Damage();
		}

		Sleep(3000);
		system("cls");
	}

	system("cls");
	cout << "GAME OVER!!";
}