#include <stdio.h>

struct recept
{
unsigned long long timestamp;
unsigned id;
unsigned recept_id;
};

int main()
{
int n, i, temp;
temp = 0;
scanf("%d", &n);

for (i = 0; i < n; i++)
{
struct recept rec;
scanf("%llu%u%u", &rec.timestamp, &rec.id, &rec.recept_id);
if (rec.recept_id <= temp)
printf("%llu %u %u\n", rec.timestamp, rec.id, rec.recept_id);
temp = rec.recept_id;
}

return 0;
}