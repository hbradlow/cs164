def foo():
    print 'hello'
    native 'what'

def foo():
    native 'what'
    print 'hello'

def foo(): print 'hello'; native 'stuff'
def foo(): print 'hello'; native 'stuff';

def foo(): native 'stuff'; print 'asdf'
def foo(): native 'stuff'; print 'asdf' ;
