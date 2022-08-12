 for(int i = index; i < index + newItemsSize; i++){
            // i - index = 0, 1, 2, 3, 4, 5 get value from index 0 to 5
            array[i] = newItems[i - index];
            cout << i - index << " "<< newItems[i - index] << endl;
        }