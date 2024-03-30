[BITS        32]
[GLOBAL LoadIDT]

LoadIDT:
        [EXTERN  idtr]
        lidt    [idtr]

        ret
