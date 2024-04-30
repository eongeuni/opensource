#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "VRS.h"

typedef struct Node {
	Hospital data;
	struct Node* prev; 
	struct Node* next;
}Node;

typedef struct List {
	Node* head;
	Node* tail;
	int count;
}List;

void InitList(List** list) {
	(*list) = (List*)malloc(sizeof(list));
	(*list)->head = NULL;
	(*list)->tail = NULL;
	(*list)->count = 0;
}


Node* CreateNode(Hospital data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->prev = NULL;
	node->next = NULL;
	return node;
}

void AddNode(List** list, Node* node) {
	if (!(*list) || !node) return;
	printf("Add Node - data : %s\n", node->data.Name);
	if ((*list)->count == 0) {
		(*list)->head = (*list)->tail = node;
		node->next = node->prev = node;
	}
	else {
		node->prev = (*list)->tail;
		node->next = (*list)->head;

		(*list)->tail->next = node;
		(*list)->head->prev = node;
		(*list)->tail = node;
	}
	(*list)->count++;
}

void PrintAllNode(List** list)
{
	if (!(*list)) return;
	printf("\n");
	if ((*list)->count == 0) {
		printf("### List is empty ###\n");
		return;
	}
	printf("### print All Node ###\n");
	int idx = 1; 
	int cnt = (*list)->count;
	Node* n = (*list)->head;
	while (idx <= cnt) {
		printf("[%d]\n", idx);
		printf("Name : %s\n", n->data.Name);
		printf("Location : %s\n", n->data.Location);
		n = n->next;
		idx++;
	}
	printf("\n");
}

void reserve_checking_up(List** list, int idx) {
	if (!(*list)) return;
	printf("\n");
	if ((*list)->count == 0) {
		printf("### Hospital Information is empty ###\n");
		return;
	}
	int tmp_idx = 1;
	Node* n = (*list)->head;
	while (tmp_idx < idx) {
		n = n->next;
		tmp_idx++;
	}
	int master_brake = 1;

	while (master_brake){
		printf("Reservation Hospital is\" ");
		printf("%s\"\n", n->data.Name);
		int reserve_time;
		printf("Please enter revation time (please enter in 24 hours): ");
		getchar();
		scanf("%d", &reserve_time);
		printf("\n");
		getchar();
		
		if (strcmp(n->data.RVI[reserve_time].patient, "")) {
			printf("This time is already reserved\n");
			for (int i = 0; i < 24; i++) {
				if (!strcmp(n->data.RVI[i].patient, "")) continue;
				
			}
			
			printf("If you want to change another hospitals, then enter another hospital index : ");
			scanf("%d", &idx);
			int tmp_idx = 1;
			n = (*list)->head;
			while (tmp_idx < idx) {
				n = n->next;
				tmp_idx++;
			}
			continue;
		}
		printf("Please enter the patient name: ");
		scanf("%[^\n]", n->data.RVI[reserve_time ].patient);  
		getchar();  
		printf("\n");

		printf("Please enter the patient purpose: ");
		scanf("%[^\n]", n->data.RVI[reserve_time].purpose);  
		getchar(); 
		printf("\n");

		printf("Please enter the patient telephone number: ");
		scanf("%[^\n]", n->data.RVI[reserve_time ].telephone_number); 
		getchar();
		printf("\n");

		printf("Please verify the input \n");
		printf("Reservation time: %d\n", reserve_time);
		printf("Name : %s\n", n->data.RVI[reserve_time].patient);
		printf("Purpose : %s\n", n->data.RVI[reserve_time].purpose);
		printf("Telephone Number : %s\n", n->data.RVI[reserve_time].telephone_number);

		int tmp;
		printf("If information is verified enter 0 else 1: ");
		scanf("%d", &tmp);
		if (tmp == 0 ){
			printf("[Reservation Success] Please enter 0");
			master_brake = 0;
		}
		else {
			printf("[Reservation Faild] Please reenter the information");
		}
	}
}
void show_hospital(List** list) {
	if (!(*list)) return;
	printf("\n");
	if ((*list)->count == 0) {
		printf("### List is empty ###\n");
		return;
	}
	printf("### Hospital List ###\n");
	int idx = 1;
	int cnt = (*list)->count;
	Node* n = (*list)->head;
	while (idx <= cnt) {
		printf("[%d]\n", idx);
		printf("Name : %s\n", n->data.Name);
		printf("Location : %s\n", n->data.Location);
		n = n->next;
		idx++;
	}
	printf("==================\n");
	printf("\n");

}

void check_reservation_status(List** list) {
	if (!(*list)) return;
	printf("\n");
	if ((*list)->count == 0) {
		printf("### Hospital Information is empty ###\n");
		return;
	}
	show_hospital(list);
	int idx;
	printf("Please enter the hospital index: ");
	scanf("%d", &idx);
	int tmp_idx = 1;
	Node* n = (*list)->head;
	while (tmp_idx < idx) {
		n = n->next;
		tmp_idx++;
	}
	int master_brake = 1;
	for (int i = 0; i < 24; i++) {
		if (!strcmp(n->data.RVI[i].patient, "")) continue;
		printf("Reserve time: %d O'clock\n", i);
		printf("Patient Name: %s\n", n->data.RVI[i].patient);
		printf("Patient Visit Purpose: %s\n", n->data.RVI[i].purpose);
		printf("Patient Telephone Number: %s\n", n->data.RVI[i].telephone_number);
		printf("===================================\n");
	}

	int tmp;
	printf("If you check the reservation status, then please enter 0: ");
	scanf("%d", &tmp);
	
}

void clear_reservation_record(List** list) {
	if (!(*list)) return;
	printf("\n");
	if ((*list)->count == 0) {
		printf("### Hospital Information is empty ###\n");
		return;
	}
	show_hospital(list);
	int idx;
	printf("Please enter the hospital index: ");
	scanf("%d", &idx);
	int tmp_idx = 1;
	Node* n = (*list)->head;
	while (tmp_idx < idx) {
		n = n->next;
		tmp_idx++;
	}

	for (int i = 0;i < 24;i++) {
		strcpy(n->data.RVI[i].patient, ""); // 빈 문자열로 초기화
		strcpy(n->data.RVI[i].purpose, ""); // 빈 문자열로 초기화
		strcpy(n->data.RVI[i].telephone_number, ""); // 빈 문자열로 초기화
	}
	printf("Reservation record was cleared. \nIf you want to go home, then please enter 0 : ");
	int tmp;
	scanf("%d", &tmp);
	printf("\n");
}

void GUI(List** list) {
	int master_brake = 1; 
	while (master_brake){
		system("cls");
		int idx = 0;
		printf("### Please enter your desired input ###\n");
		printf("1. Hospital Information Add\n");
		printf("2. Hospital Information Print\n");
		printf("3. Researvation the check up\n");
		printf("4. Check Reservation Statue\n");
		printf("5. Reservation record clear\n");
		printf("0. Exit the Hospital Reservation System\n");
		printf("============================\n");
		scanf("%d", &idx);
		int tmp = 0;
		switch (idx) {
		case 1:
			system("cls");
			printf("### Hospital Information Add ###\n");
			while (1) {
				Hospital hos;
				get_hos_info(&hos);
				AddNode(list, CreateNode(hos));
				
				printf("If you want to add more Information, then enter 1 else enter 0: ");
				scanf("%d", &tmp);
				if (tmp == 0) break;
				else {
					system("cls");
				}
			}
			break;

		case 2:
			system("cls");
			printf("### Hospital Information Print ###\n");
			PrintAllNode(list);
			printf("if you want to return home, then enter 0\n");
			scanf("%d", &tmp);
			if (tmp == 0) {
				break;
			}
		case 3:
			system("cls");
			printf("### Researvation the check up ###");
			show_hospital(list);
			printf("If you want to reseve for checking up, then plese enter the hospital index\n");
			scanf("%d", &tmp);
			reserve_checking_up(list, idx = tmp);
			break;

		case 4:
			system("cls");
			check_reservation_status(list);
			break;
		case 5:
			system("cls");
			clear_reservation_record(list);
			break;
		default:
			printf("Wrong input\n");
			printf("System out \n");
			master_brake = 0;
			break;
		}
	}

}
