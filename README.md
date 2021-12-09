# Banker's Algorithm in C++

The Banker’s algorithm is a classical algorithm for deadlock avoidance.The goal of the Banker’s
algorithm is to handle all requests without entering into the unsafe state, also called a deadlock.
Deadlocks in an operating system can be dealt in 3 ways namely: Deadlock Prevention, Deadlock
Avoidance and Deadlock Detection. Deadlock avoidance algorithm aims to preserve the system
in a stable state by taking precaution so that deadlocks never occur. The banker's algorithm is
named for the fact that it is employed in the banking system to determine whether or not a loan
can be granted to a certain individual. In a similar manner , the banker’s algorithm tests for safe
state by simulating allocation for pre-determined maximum possible quantities of all resources,
then running a "s-state" check to determine if any activities are possible, before deciding
whether or not allocation should be permitted.<br/>
When a new process is added to a system, it must define the maximum number of instances of
each resource type that it can consume, which must not exceed the total number of resources
available in the system. Once a process receives all requested resources, it must return them in
a predefined duration of time.<br/>
Resources may be allocated to a process only if it satisfies the following conditions:<br/>
1. request ≤ max, else set error condition as process has crossed maximum claim made by it.
2. request ≤ available, else process waits until resources are available
