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

// Association ����
// ������� �� �̰� ������� �� ���� Ȯ������ ���� ����̴�.
// ���� ��ü:��ǰ�� ���谡 �ƴϴ�. �׸��� ���� �뵵 �ܿ� �����ϴ�
// aggregation ���� ó�� �ٸ� Ŭ�������� ���� �� �ִ�.(������  �ǻ�1�� �ǻ�2�� ȯ��1�� �ߺ�)
// composition�� aggregation���� �� �̿��Ѵ�
