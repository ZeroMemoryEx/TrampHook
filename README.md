# Trampoline Hook

* Trampoline hooking is a method of intercepting calls to target functions,which is mainly used by antiviruses, sandboxes, and malware. 
The general idea is to redirect a function to our own, so that we can perform processing before and/or after the function does its; this could include: checking parameters, shimming, logging, spoofing returned data, and filtering calls.
Rootkits tend to use hooks to modify data returned from system calls in order to hide their presence,
whilst security software uses them to prevent/monitor potentially malicious operations.

# Vid
![2022-03-08 02-41-18](https://user-images.githubusercontent.com/60795188/157148885-88104b75-09f7-4ad2-8487-5882ce22bb28.gif)
