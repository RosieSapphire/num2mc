# Num2MC
A very basic command-line tool that converts a desired number of blocks into</br>
how many stacks you would need, and how much would be left over.</br>

To compile it, just clone the repository with</br>
`git clone https://github.com/RosieSapphire/num2mc.git`

Then `cd` into the directory and type `make`.

If you want to install it to your local bin directory, then type</br>
`sudo make install` or `sudo make uninstall` if you decide to remove it.

As for running it, just type `num2mc`, followed by the amount of blocks.

So for example:</br>
`num2mc 420`
would produce
`For 420, you need 6 stacks, with 36 left over.`

If you want the opposite functionality, where you pass in the amount of stacks</br>
and remainder you want, it will give you how many total blocks that would be.

So instead if you did</br>
`num2mc 6 36`
you'd get</br>
`For 6 stacks and 36 remaining, you need 420 blocks.'

That's it.

