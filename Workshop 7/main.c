
// STUDENT NAME: HOANG DANG KHOA NGUYEN                                     COURSE CODE: BTP100NCC.04893.2247
// STUDENT ID: 178143236


#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 20

typedef struct {
    char name[50]; // for employee's name
    int id; // for employee's id
    char department[50]; // for employee's department
    float salary; // for employee's salary
} Employee;

void addEmployee(Employee* employees, int* num_employees);
void displayEmployees(Employee* employees, int num_employees);
void searchEmployeeByID(Employee* employees, int num_employees, int id);
float calculateAverageSalary(Employee* employees, int num_employees, char* department);

int main() {
    Employee employees[MAX_EMPLOYEES];
    int choice;
    int num_employees = 0;

    printf("Employee Management System\n");

    // formatting output
    do {
        printf("\nMenu:\n");
        printf("1. Add a new employee\n");
        printf("2. Display all employees\n");
        printf("3. Search employee by ID\n");
        printf("4. Calculate average salary by department\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee(employees, &num_employees);
                break;
            case 2:
                displayEmployees(employees, num_employees);
                break;
            case 3: {
                int id;
                printf("Enter employee ID to search: ");
                scanf("%d", &id);
                searchEmployeeByID(employees, num_employees, id);
                break;
            }
            case 4: {
                char department[50];
                printf("Enter department name to calculate average salary: ");
                scanf("%s", department);
                float avg_salary = calculateAverageSalary(employees, num_employees, department);
                if (avg_salary > 0) {
                    printf("Average Salary for %s department: %.2f\n", department, avg_salary);
                } else {
                    printf("No employees found in %s department.\n", department);
                }
                break;
            }
            case 0:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}

void addEmployee(Employee* employees, int* num_employees) {
    if (*num_employees >= MAX_EMPLOYEES) {
        printf("Max Employees is reached!\n");
        return; // Terminate the function early if the database is full.
    }

    printf("Enter employee name: ");
    scanf(" %[^\n]", employees[*num_employees].name);
    printf("Enter employee ID: ");
    scanf("%d", &employees[*num_employees].id);
    printf("Enter employee department: ");
    scanf(" %[^\n]", employees[*num_employees].department);
    printf("Enter employee salary: ");
    scanf("%f", &employees[*num_employees].salary);
    printf("\nEmployee added successfully.\n");

    (*num_employees)++;
}

void displayEmployees(Employee* employees, int num_employees) {
    if (num_employees == 0) {
        printf("Database is empty.\n");
        return; // Exits early.
    }

    printf("Employee Details:\n");
    printf("-----------------\n");
    for (int i = 0; i < num_employees; i++) {
        printf("Name: %s\n", employees[i].name);
        printf("ID: %d\n", employees[i].id);
        printf("Department: %s\n", employees[i].department);
        printf("Salary: %.2f\n\n", employees[i].salary);
    }
}

void searchEmployeeByID(Employee* employees, int num_employees, int id){
    for (int i = 0; i < num_employees; i++){
        if ( id == employees[i].id){
            printf("Employee Detail:\n");
            printf("\n-----------------\n");
            printf("\nName: %s\n", employees[i].name);
            printf("ID: %d\n", id);
            printf("Department: %s\n", employees[i].department);
            printf("Salary: %.2f", employees[i].salary);
        }
        else{
            printf("Employee with ID %d not found.\n", id);
        }
        
    }
    
}

float calculateAverageSalary(Employee* employees, int num_employees, char* department){
    float total_departmentSalary = 0;
    int departmentEmployees = 0;

    for (int i = 0; i < num_employees; i++) {
        if (strcmp(employees[i].department, department) == 0){
            total_departmentSalary += employees[i].salary;
            departmentEmployees++;
        }
    }

    if (departmentEmployees == 0){
        return -1; // Since salary is obviously a positive number if there exists data for it, in this case if there is no employees for this department then the first condition will be false.
    
    }
    return total_departmentSalary / departmentEmployees;
}