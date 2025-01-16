#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct patient {
	char firstName[50];
	char lastName[50];
	int age;
	int urgency; // 1: normal, 2: urgent, 3: very urgent
	struct patient *next;
};

struct patientList {
	struct patient *head;
	struct patient *tail;
} list;

void printPatient(struct patient *p) {
	if (p != NULL) {
		printf("First Name: %s\n", p->firstName);
		printf("Last Name: %s\n", p->lastName);
		printf("Age: %d\n", p->age);
		printf("Urgency: %d\n", p->urgency);
	}
}

void addPatient(struct patient *p) {
	if (list.head == NULL) {
		list.head = p;
		list.tail = p;
	} else {
		struct patient *current = list.head;
		struct patient *previous = NULL;
		while (current != NULL && current->urgency >= p->urgency) {
			previous = current;
			current = current->next;
		}
		if (previous == NULL) {
			p->next = list.head;
			list.head = p;
		} else {
			p->next = current;
			previous->next = p;
			if (current == NULL) {
				list.tail = p;
			}
		}
	}
}

void printPatientList() {
	struct patient *current = list.head;
	while (current != NULL) {
		printPatient(current);
		current = current->next;
	}
}

void printPatientSummary() {
	struct patient *current = list.head;
	while (current != NULL) {
		printf("Last Name: %s, Urgency: %d\n", current->lastName, current->urgency);
		current = current->next;
	}
}

void main() {
	struct patient p1, p2, p3;
	p1 = (struct patient){"John", "Doe", 30, 1, NULL};
	p2 = (struct patient){"Yahya", "Zehouani", 26, 3, NULL};
	p3 = (struct patient){"Yassine", "Ahmed", 24, 2, NULL};

	struct patient p4 = {"Elhabib","TOUAOUA", 29, 1, NULL};
	
	addPatient(&p1);
	addPatient(&p2);
	addPatient(&p3);
	addPatient(&p4);

	// printPatientList();
	// printf("\n");
	printPatientSummary();

}