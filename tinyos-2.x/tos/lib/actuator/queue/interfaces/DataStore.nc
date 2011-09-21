
interface DataStore<t> {
    command t* getNewElement();
    command void deleteElement(t* elm);
    command t* DataStore.getFirst();
    command t* DataStore.getNext();
}

