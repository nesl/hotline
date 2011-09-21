
interface LinkedList {
    command void list_insert_before(list_t **head, list_t *pos, list_t *elm);
    command void list_insert_tail(list_t **head, list_t *elm);
    command void list_delete(list_t **head, list_t *del);
}

