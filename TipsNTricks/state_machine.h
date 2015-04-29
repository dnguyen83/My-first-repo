#pragma once

/* Some comment: http://channel9.msdn.com/Series/Introduction-to-C-and-DirectX-Game-Development/04

Notes:
All states can be entered, but not all states can be exited (death). One state at a time. Once in the state the code runs and runs until changed to next state. Transition are triggered by a defined event or condition

2 methods: Use State design patter, class as a each state, and have manager to manage the state

or use enum, simpler and for beginners. But this can get bulky as the system grows.

*/