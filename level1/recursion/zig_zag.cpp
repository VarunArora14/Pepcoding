// https://www.youtube.com/watch?v=R7qja_gZrvI&list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk&index=381

// When we have a recursive func, then we have 2 regions, one before call and one after
// call. In a case when we have 2 recursive calls, we have 3 regions, Pre, in and Post
// To understand multiple recursive calls we have something called euler tree
/*
https://youtu.be/R7qja_gZrvI?t=1229
Look from this part of video to understand euler tree and calls of recursive func

Think for various items while solving a recursion probelm -
1. When is Pre area
2. left call or first call of recursive func
3. When is In area
4. right call or second call of rec. func
5. When is Post area
6. When we are going deep in recursion
7. When coming out of recursion
8. What inside stack at a moment(Stack Contents)** Important
*/