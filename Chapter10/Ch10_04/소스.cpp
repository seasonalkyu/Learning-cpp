#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Doctor; // forward declaration

class Patient
{
private:
	string m_name;
	vector<Doctor*> m_doctors;
	
public:
	Patient(string name_in)
		: m_name(name_in)
	{}

	void addDoctor(Doctor* new_doctor)
	{
		m_doctors.push_back(new_doctor);
	}

	void meetDoctor();

	friend class Doctor;
};

class Doctor
{
private:
	string m_name;
	vector<Patient*> m_patients;

public:
	Doctor(string name_in)
		: m_name(name_in)
	{}

	void addPatient(Patient* new_patient)
	{
		m_patients.push_back(new_patient);
	}

	void meetPatient()
	{
		for (auto& ele : m_patients)
		{
			cout << "Meet Patients : " << ele->m_name << endl;
		}
	}

	friend class Patient;
};

void Patient::meetDoctor()
{
	for (auto& ele : m_doctors)
	{
		cout << "Meet doctor : " << ele->m_name << endl;
	}
}

int main()
{
	Patient* p1 = new Patient("JJ");
	Patient* p2 = new Patient("DD");
	Patient* p3 = new Patient("VV");

	Doctor* d1 = new Doctor("Docktor K");
	Doctor* d2 = new Doctor("Docktor L");


	p1->addDoctor(d1);
	d1->addPatient(p1);

	p2->addDoctor(d2);
	d2->addPatient(p2);

	p2->addDoctor(d1);
	d1->addPatient(p2);

	// patinets meet doctors
	p1->meetDoctor();

	// doctors meet patients
	d1->meetPatient();

	// deletes
	delete p1;
	delete p2;
	delete p3;

	delete d1;
	delete d2;

}

// Association 관계
// 어느쪽이 주 이고 어느쪽이 부 인지 확실하지 않은 경우이다.
// 따라서 전체:부품의 관계가 아니다. 그리고 서로 용도 외엔 무관하다
// aggregation 관계 처럼 다른 클래스에도 속할 수 있다.(예를들어서  의사1과 의사2에 환자1이 중복)
// composition과 aggregation보다 덜 이용한다
