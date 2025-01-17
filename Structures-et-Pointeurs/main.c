// This program manages a list of patients with different urgency levels using a linked list structure.
// It includes functions to add patients to the list, print patient details, and print a summary of patients.
// It also includes a function that remove a patient from the list based on FIFO standard

// Include necessary libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the patient structure
struct patient {
	char firstName[50]; // First name of the patient
	char lastName[50];  // Last name of the patient
	int age;            // Age of the patient
	int urgency;        // Urgency level: 1 (normal), 2 (urgent), 3 (very urgent)
	struct patient *next; // Pointer to the next patient in the list
};

// Define the patient list structure
struct patientList {
	struct patient *head; // Pointer to the first patient in the list
	struct patient *tail; // Pointer to the last patient in the list
} list; // Declare a global patient list

// Function to add a patient to the list based on urgency level
void addPatient(struct patient *p) {
	if (list.head == NULL) { // If the list is empty, add the patient as the first element
		list.head = p;
		list.tail = p;
	} else { // Otherwise, find the correct position based on urgency
		struct patient *current = list.head;
		struct patient *previous = NULL;
		while (current != NULL && current->urgency >= p->urgency) {
			previous = current;
			current = current->next;
		}
		if (previous == NULL) { // Insert at the beginning of the list
			p->next = list.head;
			list.head = p;
		} else { // Insert in the middle or end of the list
			p->next = current;
			previous->next = p;
			if (current == NULL) { // Update the tail if inserted at the end
				list.tail = p;
			}
		}
	}
}

// Function to remove a patient from the list based on FIFO standard
void removePatient() {
	if (list.head == NULL) { // If the list is empty, nothing to remove
		printf("No patients to remove.\n");
		return;
	}
	
	struct patient *temp = list.head; // Store the current head
	list.head = list.head->next; // Move the head to the next patient
	
	if (list.head == NULL) { // If the list is now empty, update the tail
		list.tail = NULL;
	}
	
	printf("Patient Last Name: %s, Urgency: %d was removed.\n\n", temp->lastName, temp->urgency);
	// free(temp); // Free the memory of the removed patient
}

// Function to print the details of a single patient
void printPatient(struct patient *p) {
	if (p != NULL) {
		printf("First Name: %s\n", p->firstName);
		printf("Last Name: %s\n", p->lastName);
		printf("Age: %d\n", p->age);
		printf("Urgency: %d\n", p->urgency);
	}
}

// Function to print the details of all patients in the list
void printPatientList() {
	struct patient *current = list.head;
	while (current != NULL) {
		printPatient(current);
		current = current->next;
	}
}

// Function to print a summary of patients (last name and urgency level)
void printPatientSummary() {
	struct patient *current = list.head;
	while (current != NULL) {
		printf("Last Name: %s, Urgency: %d\n", current->lastName, current->urgency);
		current = current->next;
	}
}

// Main function to demonstrate the functionality
void main() {
	// Create and initialize patient structures
	struct patient p1, p2, p3;
	p1 = (struct patient){"John", "Doe", 30, 1, NULL};
	p2 = (struct patient){"Yahya", "Zehouani", 26, 3, NULL};
	p3 = (struct patient){"Yassine", "Ahmed", 24, 2, NULL};

	struct patient p4 = {"Elhabib","TOUAOUA", 29, 1, NULL};
	
	// Add and remove patients from the list
	addPatient(&p1);
	addPatient(&p2);
	addPatient(&p3);
	removePatient();
	addPatient(&p4);
	removePatient();


	// Print the summary of patients
	printPatientSummary();
}