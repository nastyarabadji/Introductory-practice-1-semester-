#include <iostream>
#include <windows.h>
#include <iomanip>
#include <fstream>

using namespace std;

struct Learning_group {
	char name[255] = "";
	char surname[255] = "";
	char patronymic[255] = "";
	int course{};
	char group[20] = "";
	int year_entrance{};
	int est_phys{};
	int est_math{};
	int est_inf{};
	int est_rus{};
	int est_english{};
};

Learning_group temp;
Learning_group temp_bin;

void menu();
int correct_value();
void request(Learning_group* stud, int& col_vo);
void tabl(Learning_group* (&stud), int& col_vo);
void printTabl(Learning_group* stud, int& col_vo);
void add(Learning_group* (&stud), int& col_vo);
void change(Learning_group* stud, int& col_vo);
void change_parameters();
void deletion(Learning_group* stud, int& col_vo);
void sort_temp(Learning_group* stud, int i, int j);
void sorted(Learning_group* stud, int col_vo);
int parameters_add_sort_int(int dop_parametr);
int parameters_add_sort_char(int dop_parametr);
void parameters_sort();
void writing_data_to_a_txt(Learning_group* (&stud), int& col_vo);
void downloading_data_from_a_txt(Learning_group* (&stud), Learning_group* (&temp_bin), int& col_vo, int& count);
void writing_txt_to_a_bin(int& count);
void downloading_data_from_a_bin(Learning_group* (&stud), int& col_vo, int& count);
void case_main();
void request_txt();

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "RU");
	int count{};
	int col_vo{};
	Learning_group* temp_bin = new Learning_group[count];
	Learning_group* stud = new Learning_group[col_vo];
	int get_n{};
	menu();
	cout << "������� ��������: ";
	do {
		get_n = correct_value();
		switch (get_n) {
		case 1:
			system("cls");
			tabl(stud, col_vo);
			case_main();
			break;
		case 2:
			system("cls");
			printTabl(stud, col_vo);
			case_main();
			break;
		case 3:
			system("cls");
			add(stud, col_vo);
			case_main();
			break;
		case 4:
			system("cls");
			change(stud, col_vo);
			case_main();
			break;
		case 5:
			system("cls");
			sorted(stud, col_vo);
			case_main();
			break;
		case 6:
			system("cls");
			deletion(stud, col_vo);
			case_main();
			break;
		case 7:
			system("cls");
			request_txt();
			request(stud, col_vo);
			case_main();
			break;
		case 8:
			system("cls");
			writing_data_to_a_txt(stud, col_vo);
			case_main();
			break;
		case 9:
			system("cls");
			downloading_data_from_a_txt(stud, temp_bin, col_vo, count);
			case_main();
			break;
		case 10:
			system("cls");
			writing_txt_to_a_bin(count);
			case_main();
			break;
		case 11:
			system("cls");
			downloading_data_from_a_bin(stud, col_vo, count);
			case_main();
			break;
		case 0:
			system("cls");
			break;
		default:
			cout << "������� ���������� ��������: ";
		}
	} while (get_n != 0);
	return 0;
}

void case_main() {
	system("pause");
	system("cls");
	menu();
	cout << "������� ��������: ";
}

void request_txt() {
	cout << "������: ����������� �.�.0. � ������ ���������, ���������� 2 �� ���� ���������." << endl;
}

void menu() {
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "\t\t\t\t  ����                              " << endl;
	cout << "\t************************************************************" << endl;
	cout << "\t* 1. ��������� ������� �������                             *" << endl;
	cout << "\t* 2. ����� ������� �� �����                                *" << endl;
	cout << "\t* 3. ���������� ������� � �������                          *" << endl;
	cout << "\t* 4. ��������� ������ � �������                            *" << endl;
	cout << "\t* 5. ���������� �� ������ �� ����������                    *" << endl;
	cout << "\t* 6. �������� ������                                       *" << endl;
	cout << "\t* 7. ��c������� ������ �� �������                          *" << endl;
	cout << "\t* 8. �������� ���� ������ � ��������� ����                 *" << endl;
	cout << "\t* 9. �������� ���� ������ �� ���������� �����              *" << endl;
	cout << "\t* 10. ������� ����������� ���������� ����� � ��������      *" << endl;
	cout << "\t* 11. �������� ���� ������ �� ��������� �����              *" << endl;
	cout << "\t* 0. �����                                                 *" << endl;
	cout << "\t************************************************************" << endl;
}

void tabl(Learning_group* (&stud), int& col_vo) {
	cout << "������� ���������� ���������, ������� �� �� ������ �������� � �������: ";
	cin >> col_vo;
	system("cls");
	while ((col_vo < 1) || cin.fail() || cin.peek() != '\n') {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "������� ������������ ��������!" << endl;
		cout << "������� ���������� ���������, ������� �� �� ������ �������� � �������: ";
		cin >> col_vo;
		system("cls");
	}
	system("cls");
	stud = new Learning_group[col_vo];
	for (int i = 0; i < col_vo; i++) {
		cout << "������� ������� " << i + 1 << " ��������: ";
		cin >> stud[i].surname;
		system("cls");
		cout << "������� ��� ��������: ";
		cin >> stud[i].name;
		system("cls");
		cout << "������� �������� ��������: ";
		cin >> stud[i].patronymic;
		system("cls");
		cout << "������� ����, �� ������� ������ ������� (����� �� 1 �� 6 ������������): ";
		cin >> stud[i].course;
		system("cls");
		while ((stud[i].course < 1 || stud[i].course > 6) || cin.fail() || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "������� ������������ ��������!" << endl;
			cout << "������� ����, �� ������� ������ ������� (����� �� 1 �� 6 ������������): ";
			cin >> stud[i].course;
			system("cls");
		}
		cout << "������� ������� ������: ";
		cin >> stud[i].group;
		system("cls");
		cout << "������� ��� ����������� �������� � ��� (����� �� 1990 �� 2023 ������������): ";
		cin >> stud[i].year_entrance;
		system("cls");
		while ((stud[i].year_entrance < 1990 || stud[i].year_entrance > 2023) || cin.fail() || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "������� ������������ ��������!" << endl;
			cout << "������� ��� ����������� �������� � ��� (����� �� 1990 �� 2023 ������������): ";
			cin >> stud[i].year_entrance;
			system("cls");
		}
		cout << "������� ������ �� ������ (����� �� 0 �� 5 ������������): ";
		cin >> stud[i].est_phys;
		system("cls");
		while ((stud[i].est_phys < 0 || stud[i].est_phys > 5) || cin.fail() || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "������� ������������ ��������!" << endl;
			cout << "������� ������ �� ������ (����� �� 0 �� 5 ������������): ";
			cin >> stud[i].est_phys;
			system("cls");
		}
		cout << "������� ������ �� ���������� (����� �� 0 �� 5 ������������): ";
		cin >> stud[i].est_math;
		system("cls");
		while ((stud[i].est_math < 0 || stud[i].est_math > 5) || cin.fail() || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "������� ������������ ��������!" << endl;
			cout << "������� ������ �� ���������� (����� �� 0 �� 5 ������������): ";
			cin >> stud[i].est_math;
			system("cls");
		}
		cout << "������� ������ �� ����������� (����� �� 0 �� 5 ������������): ";
		cin >> stud[i].est_inf;
		system("cls");
		while ((stud[i].est_inf < 0 || stud[i].est_inf > 5) || cin.fail() || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "������� ������������ ��������!" << endl;
			cout << "������� ������ �� ����������� (����� �� 0 �� 5 ������������): ";
			cin >> stud[i].est_inf;
			system("cls");
		}
		cout << "������� ������ �� �������� ����� (����� �� 0 �� 5 ������������): ";
		cin >> stud[i].est_rus;
		system("cls");
		while ((stud[i].est_rus < 0 || stud[i].est_rus > 5) || cin.fail() || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "������� ������������ ��������!" << endl;
			cout << "������� ������ �� �������� ����� (����� �� 0 �� 5 ������������): ";
			cin >> stud[i].est_rus;
			system("cls");
		}
		cout << "������� ������ �� ����������� ����� (����� �� 0 �� 5 ������������): ";
		cin >> stud[i].est_english;
		system("cls");
		while ((stud[i].est_english < 0 || stud[i].est_english > 5) || cin.fail() || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "������� ������������ ��������!" << endl;
			cout << "������� ������ �� ����������� ����� (����� �� 0 �� 5 ������������): ";
			cin >> stud[i].est_english;
			system("cls");
		}
	}
	cout << "������ ������� ���������!" << endl;
}

void printTabl(Learning_group* stud, int& col_vo) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	if (col_vo == 0) {
		cout << "� ������� ��� ������ � ���������" << endl;
	}
	else {
		cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "|" << left << setw(5) << "�" << "|" << left << setw(20) << "�������" << "|" << left << setw(20) << "���" << "|" << left << setw(20) << "��������" << "|" << left << setw(10) << "����" << "|" << left << setw(17) << "������" << "|" << left << setw(10) << "��� �����������" << "|" << left << setw(10) << "������" << "|" << left << setw(10) << "�����������" << "|" << left << setw(10) << "�����-��" << "|" << left << setw(10) << "���. ��." << "|" << left << setw(10) << "����. ��." << " |" << endl;
		cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
		char line_name[21] = "", line_fam[21] = "", line_otch[21] = "";
		char name[256] = "", fam[256] = "", otch[256] = "";
		for (int i = 0; i < col_vo; i++) {
			bool flag = true;
			for (int k = 0; k < 255; k++) {
				name[k] = stud[i].name[k];
				fam[k] = stud[i].surname[k];
				otch[k] = stud[i].patronymic[k];
			}
			name[255] = '\0';
			fam[255] = '\0';
			otch[255] = '\0';
			int value_name{}, value_fam{}, value_otch{};
			value_name = strlen(stud[i].name) / 20;
			if (strlen(stud[i].name) % 20 != 0) {
				value_name += 1;
			}
			value_fam = strlen(stud[i].surname) / 20;
			if (strlen(stud[i].surname) % 20 != 0) {
				value_fam += 1;
			}
			value_otch = strlen(stud[i].patronymic) / 20;
			if (strlen(stud[i].patronymic) % 20 != 0) {
				value_otch += 1;
			}
			int max_value{};
			if (value_name >= value_fam && value_name >= value_otch) {
				max_value = value_name;
			}
			else if (value_fam >= value_name && value_fam >= value_otch) {
				max_value = value_fam;
			}
			else if (value_otch >= value_name && value_otch >= value_fam) {
				max_value = value_otch;
			}
			if (max_value > 1) {
				flag = true;
			}
			else {
				flag = false;
			}
			if (flag) {
				for (int h = 0; h < max_value; h++) {
					line_name[20] = '\0';
					line_fam[20] = '\0';
					line_otch[20] = '\0';
					for (int l = 0; l < 20; l++) {
						line_name[l] = name[l + h * 20];
						line_fam[l] = fam[l + h * 20];
						line_otch[l] = otch[l + h * 20];
					}
					line_name[20] = '\0';
					line_fam[20] = '\0';
					line_otch[20] = '\0';
					if (h == 0) {
						cout << "|" << left << setw(5) << i + 1 << "|" << left << setw(20) << line_fam << "|" << left << setw(20) << line_name << "|" << left << setw(20) << line_otch << "|" << left << setw(10) << stud[i].course << "|" << left << setw(17) << stud[i].group << "|" << left << setw(10) << stud[i].year_entrance << "     " << "|" << left << setw(10) << stud[i].est_phys << "|" << left << setw(10) << stud[i].est_inf << " |" << left << setw(10) << stud[i].est_math << "|" << left << setw(10) << stud[i].est_rus << "|" << left << setw(10) << stud[i].est_english << " |" << endl;
					}
					else {
						cout << "|" << "     " << "|" << left << setw(20) << line_fam << "|" << left << setw(20) << line_name << "|" << left << setw(20) << line_otch << "|" << "          " << "|" << "                 " << "|" << "               " << "|" << "          " << "|" << "          " << " |" << "          " << "|" << "          " << "|" << "          " << " |" << endl;
					}
					for (int k = 0; k < 20; k++) {
						line_name[k] = ' ';
						line_fam[k] = ' ';
						line_otch[k] = ' ';
					}
					line_name[20] = '\0';
					line_fam[20] = '\0';
					line_otch[20] = '\0';
				}
			}
			else {
				cout << "|" << left << setw(5) << i + 1 << "|" << left << setw(20) << stud[i].surname << "|" << left << setw(20) << stud[i].name << "|" << left << setw(20) << stud[i].patronymic << "|" << left << setw(10) << stud[i].course << "|" << left << setw(17) << stud[i].group << "|" << left << setw(10) << stud[i].year_entrance << "     " << "|" << left << setw(10) << stud[i].est_phys << "|" << left << setw(10) << stud[i].est_inf << " |" << left << setw(10) << stud[i].est_math << "|" << left << setw(10) << stud[i].est_rus << "|" << left << setw(10) << stud[i].est_english << " |" << endl;
			}
			cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
		}
	}
}

void request(Learning_group* stud, int& col_vo) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int count_s{};
	for (int i = 0; i < col_vo; i++) {
		int count{};
		if (stud[i].est_english == 2) {
			count++;
		}
		if (stud[i].est_inf == 2) {
			count++;
		}
		if (stud[i].est_math == 2) {
			count++;
		}
		if (stud[i].est_phys == 2) {
			count++;
		}
		if (stud[i].est_rus == 2) {
			count++;
		}
		if (count == 3) {
			cout << "���: " << stud[i].surname << " " << stud[i].name << " " << stud[i].patronymic << endl;
			cout << "������: " << stud[i].group << endl;
			count_s += 1;
		}
	}
	if (count_s == 0) {
		cout << "��� ������ �� �������" << endl;
	}
}

int correct_value() {
	int n{};
	bool flag{};
	do {
		flag = false;
		if ((cin >> n).fail()) {
			cin.clear();
			cin.ignore((numeric_limits<streamsize>::max)(), '\n');
			system("cls");
			cout << "������� �����: ";
			flag = true;
		}
	} while (flag);
	return n;
}

void change_parameters() {
	cout << "1. �������� ��� ��������" << endl;
	cout << "2. �������� ������� ��������" << endl;
	cout << "3. �������� �������� ��������" << endl;
	cout << "4. �������� ���� ��������" << endl;
	cout << "5. �������� ������ ��������" << endl;
	cout << "6. �������� ��� ����������� ��������" << endl;
	cout << "7. �������� ������ �� ������" << endl;
	cout << "8. �������� ������ �� ����������" << endl;
	cout << "9. �������� ������ �� �����������" << endl;
	cout << "10. �������� ������ �� �������� �����" << endl;
	cout << "11. �������� ������ �� ����������� �����" << endl;
}

void change(Learning_group* stud, int& col_vo) {
	if (col_vo == 0) {
		cout << "� ������� ��� ������" << endl;
	}
	else {
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		int number_stud{};
		printTabl(stud, col_vo);
		cout << "������� ����� ��������, ��������, �������� ������ ��������: ";
		cin >> number_stud;
		system("cls");
		while ((number_stud < 1 || number_stud > col_vo) || cin.fail() || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "������� ������������ ��������!" << endl;
			printTabl(stud, col_vo);
			cout << "������� ����� ��������, ��������, �������� ������ ��������: ";
			cin >> number_stud;
			system("cls");
		}
		change_parameters();
		int number_parametr{};
		cout << "������� ����� � ��� ����������, ������� �� �� ������ ��������: ";
		cin >> number_parametr;
		system("cls");
		while ((number_parametr < 1 || number_parametr > 11) || cin.fail() || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "������� ������������ ��������!" << endl;
			change_parameters();
			cout << "������� ����� � ��� ����������, ������� �� �� ������ ��������: ";
			cin >> number_parametr;
			system("cls");
		}
		switch (number_parametr) {
		case 1:
			cout << "������� ��� ��������: ";
			cin >> stud[number_stud - 1].name;
			break;
		case 2:
			cout << "������� ������� ��������: ";
			cin >> stud[number_stud - 1].surname;
			break;
		case 3:
			cout << "������� �������� ��������: ";
			cin >> stud[number_stud - 1].patronymic;
			break;
		case 4:
			cout << "������� ���� �������� (����� �� 1 �� 6 ������������): ";
			cin >> stud[number_stud - 1].course;
			system("cls");
			while ((stud[number_stud - 1].course < 1 || stud[number_stud - 1].course > 6) || cin.fail() || cin.peek() != '\n') {
				cin.clear();
				cin.ignore(100, '\n');
				cout << "������� ������������ ��������!" << endl;
				cout << "������� ����, �� ������� ������ ������� (����� �� 1 �� 6 ������������): ";
				cin >> stud[number_stud].course;
				system("cls");
			}
			break;
		case 5:
			cout << "������� ������ ��������: ";
			cin >> stud[number_stud - 1].group;
			break;
		case 6:
			cout << "������� ��� ����������� �������� � ��� (����� �� 1990 �� 2023 ������������): ";
			cin >> stud[number_stud - 1].year_entrance;
			system("cls");
			while ((stud[number_stud - 1].year_entrance < 1990 || stud[number_stud - 1].year_entrance > 2023) || cin.fail() || cin.peek() != '\n') {
				cin.clear();
				cin.ignore(100, '\n');
				cout << "������� ������������ ��������!" << endl;
				cout << "������� ��� ����������� �������� � ��� (����� �� 1990 �� 2023 ������������): ";
				cin >> stud[number_stud - 1].year_entrance;
				system("cls");
			}
			break;
		case 7:
			cout << "������� ������ �� ������ (����� �� 0 �� 5 ������������): ";
			cin >> stud[number_stud - 1].est_phys;
			system("cls");
			while ((stud[number_stud - 1].est_phys < 0 || stud[number_stud - 1].est_phys > 5) || cin.fail() || cin.peek() != '\n') {
				cin.clear();
				cin.ignore(100, '\n');
				cout << "������� ������������ ��������!" << endl;
				cout << "������� ������ �� ������ (����� �� 0 �� 5 ������������): ";
				cin >> stud[number_stud - 1].est_phys;
				system("cls");
			}
			break;
		case 8:
			cout << "������� ������ �� ���������� (����� �� 0 �� 5 ������������): ";
			cin >> stud[number_stud - 1].est_math;
			system("cls");
			while ((stud[number_stud - 1].est_math < 0 || stud[number_stud - 1].est_math > 5) || cin.fail() || cin.peek() != '\n') {
				cin.clear();
				cin.ignore(100, '\n');
				cout << "������� ������������ ��������!" << endl;
				cout << "������� ������ �� ���������� (����� �� 0 �� 5 ������������): ";
				cin >> stud[number_stud - 1].est_math;
				system("cls");
			}
			break;
		case 9:
			cout << "������� ������ �� ����������� (����� �� 0 �� 5 ������������): ";
			cin >> stud[number_stud - 1].est_inf;
			system("cls");
			while ((stud[number_stud - 1].est_inf < 0 || stud[number_stud - 1].est_inf > 5) || cin.fail() || cin.peek() != '\n') {
				cin.clear();
				cin.ignore(100, '\n');
				cout << "������� ������������ ��������!" << endl;
				cout << "������� ������ �� ����������� (����� �� 0 �� 5 ������������): ";
				cin >> stud[number_stud - 1].est_inf;
				system("cls");
			}
			break;
		case 10:
			cout << "������� ������ �� �������� ����� (����� �� 0 �� 5 ������������): ";
			cin >> stud[number_stud - 1].est_rus;
			system("cls");
			while ((stud[number_stud - 1].est_rus < 0 || stud[number_stud - 1].est_rus > 5) || cin.fail() || cin.peek() != '\n') {
				cin.clear();
				cin.ignore(100, '\n');
				cout << "������� ������������ ��������!" << endl;
				cout << "������� ������ �� �������� ����� (����� �� 0 �� 5 ������������): ";
				cin >> stud[number_stud - 1].est_rus;
				system("cls");
			}
			break;
		case 11:
			cout << "������� ������ �� ����������� �����: ";
			cin >> stud[number_stud - 1].est_english;
			system("cls");
			while ((stud[number_stud - 1].est_rus < 0 || stud[number_stud - 1].est_rus > 5) || cin.fail() || cin.peek() != '\n') {
				cin.clear();
				cin.ignore(100, '\n');
				cout << "������� ������������ ��������!" << endl;
				cout << "������� ������ �� ����������� ����� (����� �� 0 �� 5 ������������): ";
				cin >> stud[number_stud - 1].est_english;
				system("cls");
			}
			break;
		}
		system("cls");
		cout << "������ ������� ��������!" << endl;
	}
}

void add(Learning_group* (&stud), int& col_vo) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Learning_group* temp_add = new Learning_group[col_vo];
	for (int i = 0; i < col_vo; i++) {
		temp_add[i] = stud[i];
	}
	col_vo++;
	stud = new Learning_group[col_vo];
	for (int i = 0; i < col_vo; i++) {
		stud[i] = temp_add[i];
	}
	cout << "������� ������� " << col_vo << " ��������: ";
	cin >> stud[col_vo - 1].surname;
	system("cls");
	cout << "������� ��� ��������: ";
	cin >> stud[col_vo - 1].name;
	system("cls");
	cout << "������� �������� ��������: ";
	cin >> stud[col_vo - 1].patronymic;
	system("cls");
	cout << "������� ����, �� ������� ������ ������� (����� �� 1 �� 6 ������������): ";
	cin >> stud[col_vo - 1].course;
	system("cls");
	while ((stud[col_vo - 1].course < 1 || stud[col_vo - 1].course > 6) || cin.fail() || cin.peek() != '\n') {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "������� ������������ ��������!" << endl;
		cout << "������� ����, �� ������� ������ ������� (����� �� 1 �� 6 ������������): ";
		cin >> stud[col_vo - 1].course;
		system("cls");
	}
	cout << "������� ������� ������: ";
	cin >> stud[col_vo - 1].group;
	system("cls");
	cout << "������� ��� ����������� �������� � ��� (����� �� 1990 �� 2023 ������������): ";
	cin >> stud[col_vo - 1].year_entrance;
	system("cls");
	while ((stud[col_vo - 1].year_entrance < 1990 || stud[col_vo - 1].year_entrance > 2023) || cin.fail() || cin.peek() != '\n') {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "������� ������������ ��������!" << endl;
		cout << "������� ��� ����������� �������� � ��� (����� �� 1990 �� 2023 ������������): ";
		cin >> stud[col_vo - 1].year_entrance;
		system("cls");
	}
	cout << "������� ������ �� ������ (����� �� 0 �� 5 ������������): ";
	cin >> stud[col_vo - 1].est_phys;
	system("cls");
	while ((stud[col_vo - 1].est_phys < 0 || stud[col_vo - 1].est_phys > 5) || cin.fail() || cin.peek() != '\n') {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "������� ������������ ��������!" << endl;
		cout << "������� ������ �� ������ (����� �� 0 �� 5 ������������): ";
		cin >> stud[col_vo - 1].est_phys;
		system("cls");
	}
	cout << "������� ������ �� ���������� (����� �� 0 �� 5 ������������): ";
	cin >> stud[col_vo - 1].est_math;
	system("cls");
	while ((stud[col_vo - 1].est_math < 0 || stud[col_vo - 1].est_math > 5) || cin.fail() || cin.peek() != '\n') {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "������� ������������ ��������!" << endl;
		cout << "������� ������ �� ���������� (����� �� 0 �� 5 ������������): ";
		cin >> stud[col_vo - 1].est_math;
		system("cls");
	}
	cout << "������� ������ �� ����������� (����� �� 0 �� 5 ������������): ";
	cin >> stud[col_vo - 1].est_inf;
	system("cls");
	while ((stud[col_vo - 1].est_inf < 0 || stud[col_vo - 1].est_inf > 5) || cin.fail() || cin.peek() != '\n') {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "������� ������������ ��������!" << endl;
		cout << "������� ������ �� ����������� (����� �� 0 �� 5 ������������): ";
		cin >> stud[col_vo - 1].est_inf;
		system("cls");
	}
	cout << "������� ������ �� �������� ����� (����� �� 0 �� 5 ������������): ";
	cin >> stud[col_vo - 1].est_rus;
	system("cls");
	while ((stud[col_vo - 1].est_rus < 0 || stud[col_vo - 1].est_rus > 5) || cin.fail() || cin.peek() != '\n') {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "������� ������������ ��������!" << endl;
		cout << "������� ������ �� �������� ����� (����� �� 0 �� 5 ������������): ";
		cin >> stud[col_vo - 1].est_rus;
		system("cls");
	}
	cout << "������� ������ �� ����������� ����� (����� �� 0 �� 5 ������������): ";
	cin >> stud[col_vo - 1].est_english;
	system("cls");
	while ((stud[col_vo - 1].est_rus < 0 || stud[col_vo - 1].est_rus > 5) || cin.fail() || cin.peek() != '\n') {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "������� ������������ ��������!" << endl;
		cout << "������� ������ �� ����������� ����� (����� �� 0 �� 5 ������������): ";
		cin >> stud[col_vo - 1].est_english;
		system("cls");
	}
	delete[] temp_add;
	system("cls");
	cout << "������ ������� ���������!";
	cout << endl;
}

void deletion(Learning_group* stud, int& col_vo) {
	if (col_vo == 0) {
		cout << "� ������� ��� ������" << endl;
	}
	else {
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		printTabl(stud, col_vo);
		int stud_udalenie{};
		cout << "������� ����� ��������, �������� ������ �������: ";
		cin >> stud_udalenie;
		system("cls");
		while ((stud_udalenie < 1 || stud_udalenie > col_vo) || cin.fail() || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "������� ������������ ��������!" << endl;
			printTabl(stud, col_vo);
			cout << "������� ����� ��������, �������� ������ ������� : ";
			cin >> stud_udalenie;
			system("cls");
		}
		system("cls");
		for (int i = stud_udalenie - 1; i < col_vo - 1; i++) {
			stud[i] = stud[i + 1];
		}
		col_vo--;
		system("cls");
		cout << "������ ������� �������!" << endl;
	}
}

void sort_temp(Learning_group* stud, int i, int j) {
	temp = stud[i];
	stud[i] = stud[j];
	stud[j] = temp;
}

void parameters_sort() {
	cout << "1. ������������� �� �����" << endl;
	cout << "2. ������������� �� �������" << endl;
	cout << "3. ������������� �� ��������" << endl;
	cout << "4. ������������� �� �����" << endl;
	cout << "5. ������������� �� ������" << endl;
	cout << "6. ������������� �� ���� �����������" << endl;
	cout << "7. ������������� �� ������ �� ������" << endl;
	cout << "8. ������������� �� ������ �� ����������" << endl;
	cout << "9. ������������� �� ������ �� �����������" << endl;
	cout << "10. ������������� �� ������ �� �������� �����" << endl;
	cout << "11. ������������� �� ������ �� ����������� �����" << endl;
}

int parameters_add_sort_int(int dop_parametr) {
	cout << "1. ������������� �� �����������" << endl;
	cout << "2. ������������� �� ��������" << endl;
	cout << "��� �� ������ �������������? ������� �����: ";
	cin >> dop_parametr;
	system("cls");
	while ((dop_parametr < 1 || dop_parametr > 2) || cin.fail() || cin.peek() != '\n') {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "������� ������������ ��������!" << endl;
		cout << "1. ������������� �� �����������" << endl;
		cout << "2. ������������� �� ��������" << endl;
		cout << "��� �� ������ �������������? ������� ����� (1 ��� 2): ";
		cin >> dop_parametr;
		system("cls");
	}
	return dop_parametr;
}

int parameters_add_sort_char(int dop_parametr) {
	cout << "1. ������������� � ���������� �������" << endl;
	cout << "2. ������������� � �������� ���������� �������" << endl;
	cout << "��� �� ������ �������������? ������� �����: ";
	cin >> dop_parametr;
	system("cls");
	while ((dop_parametr < 1 || dop_parametr > 2) || cin.fail() || cin.peek() != '\n') {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "������� ������������ ��������!" << endl;
		cout << "1. ������������� � ���������� �������" << endl;
		cout << "2. ������������� � �������� ���������� �������" << endl;
		cout << "��� �� ������ �������������? ������� ����� (1 ��� 2): ";
		cin >> dop_parametr;
		system("cls");
	}
	return dop_parametr;
}

void sorted(Learning_group* stud, int col_vo) {
	if (col_vo == 0) {
		cout << "� ������� ��� ������" << endl;
	}
	else {
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		int parametr_s{};
		parameters_sort();
		cout << "������� ��������, �� �������� �� ������ ������������� �������: ";
		cin >> parametr_s;
		system("cls");
		while ((parametr_s < 1 || parametr_s > 11) || cin.fail() || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "������� ������������ ��������!" << endl;
			parameters_sort();
			cout << "������� ��������, �� �������� �� ������ ������������� ������� (����� �� 1 �� 11 ������������): ";
			cin >> parametr_s;
			system("cls");
		}
		int dop_parametr{};
		switch (parametr_s) {
		case 1:
			dop_parametr = parameters_add_sort_char(dop_parametr);
			for (int i = 0; i < col_vo; i++) {
				for (int j = i + 1; j < col_vo; j++) {
					if (dop_parametr == 1) {
						if (stud[i].name[0] > stud[j].name[0]) {
							sort_temp(stud, i, j);
						}
					}
					else if (dop_parametr == 2) {
						if (stud[i].name[0] < stud[j].name[0]) {
							sort_temp(stud, i, j);
						}
					}
				}
			}
			system("cls");
			cout << "������ �������������!" << endl;
			break;
		case 2:
			dop_parametr = parameters_add_sort_char(dop_parametr);
			for (int i = 0; i < col_vo; i++) {
				for (int j = i + 1; j < col_vo; j++) {
					if (dop_parametr == 1) {
						if (stud[i].surname[0] > stud[j].surname[0]) {
							sort_temp(stud, i, j);
						}
					}
					else if (dop_parametr == 2) {
						if (stud[i].surname[0] < stud[j].surname[0]) {
							sort_temp(stud, i, j);
						}
					}
				}
			}
			system("cls");
			cout << "������ �������������!" << endl;
			break;
		case 3:
			dop_parametr = parameters_add_sort_char(dop_parametr);
			for (int i = 0; i < col_vo; i++) {
				for (int j = i + 1; j < col_vo; j++) {
					if (dop_parametr == 1) {
						if (stud[i].patronymic[0] > stud[j].patronymic[0]) {
							sort_temp(stud, i, j);
						}
					}
					else if (dop_parametr == 2) {
						if (stud[i].patronymic[0] < stud[j].patronymic[0]) {
							sort_temp(stud, i, j);
						}
					}
				}
			}
			system("cls");
			cout << "������ �������������!" << endl;
			break;
		case 4:
			dop_parametr = parameters_add_sort_int(dop_parametr);
			for (int i = 0; i < col_vo; i++) {
				for (int j = i + 1; j < col_vo; j++) {
					if (dop_parametr == 1) {
						if (stud[i].course > stud[j].course) {
							sort_temp(stud, i, j);
						}
					}
					else if (dop_parametr == 2) {
						if (stud[i].course < stud[j].course) {
							sort_temp(stud, i, j);
						}
					}
				}
			}
			system("cls");
			cout << "������ �������������!" << endl;
			break;
		case 5:
			dop_parametr = parameters_add_sort_char(dop_parametr);
			for (int i = 0; i < col_vo; i++) {
				for (int j = i + 1; j < col_vo; j++) {
					if (dop_parametr == 1) {
						if (strcmp(stud[i].group, stud[j].group) > 0) {
							sort_temp(stud, i, j);
						}
					}
					else if (dop_parametr == 2) {
						if (strcmp(stud[i].group, stud[j].group) < 0) {
							sort_temp(stud, i, j);
						}
					}
				}
			}
			system("cls");
			cout << "������ �������������!" << endl;
			break;
		case 6:
			dop_parametr = parameters_add_sort_int(dop_parametr);
			for (int i = 0; i < col_vo; i++) {
				for (int j = i + 1; j < col_vo; j++) {
					if (dop_parametr == 1) {
						if (stud[i].year_entrance > stud[j].year_entrance) {
							sort_temp(stud, i, j);
						}
					}
					else if (dop_parametr == 2) {
						if (stud[i].year_entrance < stud[j].year_entrance) {
							sort_temp(stud, i, j);
						}
					}
				}
			}
			system("cls");
			cout << "������ �������������!" << endl;
			break;
		case 7:
			dop_parametr = parameters_add_sort_int(dop_parametr);
			for (int i = 0; i < col_vo; i++) {
				for (int j = i + 1; j < col_vo; j++) {
					if (dop_parametr == 1) {
						if (stud[i].est_phys > stud[j].est_phys) {
							sort_temp(stud, i, j);
						}
					}
					else if (dop_parametr == 2) {
						if (stud[i].est_phys < stud[j].est_phys) {
							sort_temp(stud, i, j);
						}
					}
				}
			}
			system("cls");
			cout << "������ �������������!" << endl;
			break;
		case 8:
			dop_parametr = parameters_add_sort_int(dop_parametr);
			for (int i = 0; i < col_vo; i++) {
				for (int j = i + 1; j < col_vo; j++) {
					if (dop_parametr == 1) {
						if (stud[i].est_math > stud[j].est_math) {
							sort_temp(stud, i, j);
						}
					}
					else if (dop_parametr == 2) {
						if (stud[i].est_math < stud[j].est_math) {
							sort_temp(stud, i, j);
						}
					}
				}
			}
			system("cls");
			cout << "������ �������������!" << endl;
			break;
		case 9:
			dop_parametr = parameters_add_sort_int(dop_parametr);
			for (int i = 0; i < col_vo; i++) {
				for (int j = i + 1; j < col_vo; j++) {
					if (dop_parametr == 1) {
						if (stud[i].est_inf > stud[j].est_inf) {
							sort_temp(stud, i, j);
						}
					}
					else if (dop_parametr == 2) {
						if (stud[i].est_inf < stud[j].est_inf) {
							sort_temp(stud, i, j);
						}
					}
				}
			}
			system("cls");
			cout << "������ �������������!" << endl;
			break;
		case 10:
			dop_parametr = parameters_add_sort_int(dop_parametr);
			for (int i = 0; i < col_vo; i++) {
				for (int j = i + 1; j < col_vo; j++) {
					if (dop_parametr == 1) {
						if (stud[i].est_rus > stud[j].est_rus) {
							sort_temp(stud, i, j);
						}
					}
					else if (dop_parametr == 2) {
						if (stud[i].est_rus < stud[j].est_rus) {
							sort_temp(stud, i, j);
						}
					}
				}
			}
			system("cls");
			cout << "������ �������������!" << endl;
			break;
		case 11:
			dop_parametr = parameters_add_sort_int(dop_parametr);
			for (int i = 0; i < col_vo; i++) {
				for (int j = i + 1; j < col_vo; j++) {
					if (dop_parametr == 1) {
						if (stud[i].est_english > stud[j].est_english) {
							sort_temp(stud, i, j);
						}
					}
					else if (dop_parametr == 2) {
						if (stud[i].est_english < stud[j].est_english) {
							sort_temp(stud, i, j);
						}
					}
				}
			}
			system("cls");
			cout << "������ �������������!" << endl;
			break;
		}
	}
}

void writing_data_to_a_txt(Learning_group* (&stud), int& col_vo) {
	ofstream fout;
	fout.open("Students.txt");
	if (fout.is_open()) {
		fout << col_vo << "\n";
		for (int i = 0; i < col_vo; i++) {
			fout << stud[i].surname << ' ' << stud[i].name << ' '
				<< stud[i].patronymic << ' ' << stud[i].course << ' '
				<< stud[i].group << ' ' << stud[i].year_entrance << ' '
				<< stud[i].est_phys << ' ' << stud[i].est_inf << ' '
				<< stud[i].est_math << ' ' << stud[i].est_rus << ' '
				<< stud[i].est_english << "\n";
		}
	}
	else {
		cout << "������ �������� �����!" << endl;
	}
	fout.close();
	system("cls");
	cout << "������ �������� � ��������� ����!" << endl;
}

void downloading_data_from_a_txt(Learning_group* (&stud), Learning_group* (&temp_bin), int& col_vo, int& count) {
	ifstream fin;
	fin.open("Students.txt");
	if (fin.is_open()) {
		fin >> count;
		col_vo = count;
		cout << col_vo;
		stud = new Learning_group[col_vo];
		temp_bin = new Learning_group[count];
		for (int i = 0; i < col_vo; i++) {
			fin >> stud[i].surname >> stud[i].name
				>> stud[i].patronymic >> stud[i].course
				>> stud[i].group >> stud[i].year_entrance
				>> stud[i].est_phys >> stud[i].est_inf
				>> stud[i].est_math >> stud[i].est_rus
				>> stud[i].est_english;
		}
	}
	else {
		cout << "������ �������� �����!" << endl;
	}
	fin.close();
	system("cls");
	cout << "������ ��������� � ���� ������!" << endl;
}

void writing_txt_to_a_bin(int& count) {
	ifstream fin("Students.txt");
	Learning_group temp_bin[100];
	if (fin.is_open()) {
		fin >> count;
		for (int i = 0; i < count; i++) {
			fin >> temp_bin[i].surname >> temp_bin[i].name
				>> temp_bin[i].patronymic >> temp_bin[i].course
				>> temp_bin[i].group >> temp_bin[i].year_entrance
				>> temp_bin[i].est_phys >> temp_bin[i].est_inf
				>> temp_bin[i].est_math >> temp_bin[i].est_rus
				>> temp_bin[i].est_english;
		}
	}
	else {
		cout << "������ �������� �����!" << endl;
	}
	fin.close();
	ofstream fout("Students.bin", ios::binary);
	if (fout.is_open()) {
		for (int i = 0; i < count; i++) {
			fout.write((char*)(&temp_bin[i]), sizeof(Learning_group));
		}
		fout.close();
		system("cls");
		cout << "������ ���������� � �������� ����!" << endl;
	}
	else {
		cout << "������ �������� �����!" << endl;
	}
}

void downloading_data_from_a_bin(Learning_group* (&stud), int& col_vo, int& count) {
	ifstream fin;
	fin.open("Students.bin", ios::binary);
	if (fin.is_open()) {
		col_vo = count;
		stud = new Learning_group[col_vo];
		for (int i = 0; i < col_vo; i++) {
			fin.read((char*)(&stud[i]), sizeof(Learning_group));
		}
	}
	else {
		cout << "������ �������� �����!" << endl;
	}
	fin.close();
	system("cls");
	cout << "������ ��������� � ���� ������!" << endl;
}