#Solution: 

##newphonewhodis_32

Through an analysis of the 32 bit ELF, we can see that there are manipulations in the string "Wakainaiooooo", effectively itterating through the string. However, if we examine closely we can see that there are clear indications of it going backwards through the string and saving it to a new string.
As such we can determine that this string is being reversed and the answer is : "oooooianiakaW"


Another way that this could be tackled is by utilizing a tool called ltrace which allows for introspection into calls to library calls. Through this utility it is trivial to find the string that is being compared and again the answer "oooooianiakaW" can be derived.

###Sample output of ltrace:
ltrace ./newphonewhodis_elf_32
__libc_start_main(0x40072d, 1, 0x7fff706da338, 0x400840 <unfinished ...>
__isoc99_scanf(0x4008d6, 0x7fff706da230, 87, 0aaaaaaaaaaaaa
)               = 1
strlen("aaaaaaaaaaaaa")                                       = 13
strcmp("aaaaaaaaaaaaa", "oooooianiakaW")                      = -14
printf("Wrong numba.")                                        = 12
Wrong numba.+++ exited (status 0) +++
