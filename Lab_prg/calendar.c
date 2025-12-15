#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Day {
char *name;
int date;
char *description;
};
struct Day *create_calendar();
void read_calendar(struct Day *calendar);
void display_calendar(struct Day *calendar);
void free_calendar(struct Day *calendar);
int main() {
struct Day *calendar = create_calendar();
read_calendar(calendar);
display_calendar(calendar);
free_calendar(calendar);
return 0;
}
struct Day *create_calendar() {
struct Day *calendar = (struct Day *)malloc(7 * sizeof(struct Day));
if (calendar == NULL) {
printf("Memory allocation failed\n");
exit(1);
}
return calendar;
}
void read_calendar(struct Day *calendar) {
for (int i = 0; i < 7; i++) {
calendar[i].name = (char *)malloc(100 * sizeof(char));
calendar[i].description = (char *)malloc(200 * sizeof(char));
if (calendar[i].name == NULL || calendar[i].description == NULL) {
printf("Memory allocation failed\n");
exit(1);
}
printf("Enter day name: ");
scanf("%s", calendar[i].name);
printf("Enter date: ");
scanf("%d", &calendar[i].date);
getchar();
printf("Enter description: ");
fgets(calendar[i].description, 200, stdin);
size_t len = strlen(calendar[i].description);
if (len > 0 && calendar[i].description[len - 1] == '\n') {
calendar[i].description[len - 1] = '\0';
}
}
}
void display_calendar(struct Day *calendar) {
printf("\nWeek's Activity Details Report\n");
printf("------------------------------\n");
printf("Day\tDate\tDescription\n");
printf("------------------------------\n");
for (int i = 0; i < 7; i++) {
printf("%s\t%d\t%s\n",
calendar[i].name,
calendar[i].date,
calendar[i].description);
}
printf("------------------------------\n");
}
void free_calendar(struct Day *calendar) {
for (int i = 0; i < 7; i++) {
free(calendar[i].name);
free(calendar[i].description);
}
free(calendar);
}