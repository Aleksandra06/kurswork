#include "pch.h"

void read_base(FILE *f, list *l) {
	record* tmp = new record();
	list* tmpl;
	fread((record *)tmp, sizeof(record), 1, f);
	l->data = tmp;
	l->prior = NULL;
	l->next = NULL;
	for (int i = 1; i < N; i++) {
		tmp = new record();
		fread((record *)tmp, sizeof(record), 1, f);
		tmpl = l;
		l = l->next = new list();
		l->data = tmp;
		l->prior = tmpl;
		l->next = NULL;
	}
}
