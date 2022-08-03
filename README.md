# Trampoline Hook

* Trampoline hooking is a method of intercepting calls to target functions,which is mainly used by antiviruses, sandboxes, and malware. 
The general idea is to redirect a function to our own, so that we can perform processing before and/or after the function does its; this could include: checking parameters, shimming, logging, spoofing returned data, and filtering calls.
Rootkits tend to use hooks to modify data returned from system calls in order to hide their presence,
whilst security software uses them to prevent/monitor potentially malicious operations.
