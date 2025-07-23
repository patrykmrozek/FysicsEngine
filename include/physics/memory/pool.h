/*
allocate a large amount of memory and manually manage alloations
avoid overhead from default malloc() free()
TODO:
    fyMemoryPool {void* memory, size_t capacity, size_t used};
    fyPoolInit()
    fyPoolAlloc()
    fyPoolReset() //just reset used to 0 - dont free
*/ 
