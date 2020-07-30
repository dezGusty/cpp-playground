# Q&A

1. Is it faster to use the heap or the stack? Why?

Typically, due to data locality, the stack is faster. But there's no guarantee. However, the stack IS limited.

A more detailed answer on **stack vs heap performance-wise** : <https://stackoverflow.com/questions/24057331/is-accessing-data-in-the-heap-faster-than-from-the-stack/24057744#2405774

Additional resource: here's an older article describing the performance differences stemming from memory access and why using pointers would be slower due to more cache misses. ~30 min read: <https://gameprogrammingpatterns.com/data-locality.htm>.

While the article is about C++ game engines, it's highly recommended to all, as it applies to all code running on a CPU, regardless of the original language.
