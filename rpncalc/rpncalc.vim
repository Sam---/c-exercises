sy match rpnErr '\v\S'
sy match rpnWord '\v[a-zA-Z]+'
sy match rpnSymbol '\v[-+!@#$%^&*(),?/\~`]+'
sy match rpnDigit '\v[-+]?\d+(\.\d+)?'

hi link rpnDigit Number
hi link rpnWord Identifier
hi link rpnSymbol Operator
hi link rpnErr Error
