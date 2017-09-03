

int test1()
{
    int num[5] = {1,3,12,34,56};
    LinkNode *link = createLink(num, 5);
    LinkNode *next = link->next;

    while (next) {
        printf("%d ", next->data);
        next = next->next;
    }

    printf("\n");
    free(link);

    return 0;
}
