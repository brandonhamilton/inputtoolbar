/*
 *  UIInputToolbarViewController.m
 *  
 *  Created by Brandon Hamilton on 2011/05/03.
 *  Copyright 2011 Brandon Hamilton.
 *  
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *  
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *  
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 *  THE SOFTWARE.
 */

#import "UIInputToolbarViewController.h"

#define kStatusBarHeight      [UIApplication sharedApplication].statusBarFrame.size.height
#define kDefaultToolbarHeight 40

@implementation UIInputToolbarViewController

@synthesize inputToolbar;

- (void)dealloc
{
    [inputToolbar release];
    [super dealloc];
}

#pragma mark - View lifecycle

- (void)loadView
{
    [super loadView];
    
    /* Calculate screen size */
    CGRect screenFrame = [[UIScreen mainScreen] applicationFrame];
    self.view = [[UIView alloc] initWithFrame:screenFrame];
    self.view.backgroundColor = [UIColor whiteColor];
    self.view.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
    /* Create toolbar */
    self.inputToolbar = [[UIInputToolbar alloc] initWithFrame:CGRectMake(0, screenFrame.size.height-kDefaultToolbarHeight, screenFrame.size.width, kDefaultToolbarHeight)];
    [self.view addSubview:self.inputToolbar];
    inputToolbar.delegate = self;
    inputToolbar.textView.placeholder = NSLocalizedString(@"Placeholder", nil);
}

- (void)viewWillAppear:(BOOL)animated 
{
	[super viewWillAppear:animated];
	/* Listen for keyboard */
	[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(keyboardWillShow:) name:UIKeyboardWillShowNotification object:nil];
	[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(keyboardWillHide:) name:UIKeyboardWillHideNotification object:nil];

    [inputToolbar becomeFirstResponder];
}

- (void)viewWillDisappear:(BOOL)animated 
{
	[super viewWillDisappear:animated];
	/* No longer listen for keyboard */
	[[NSNotificationCenter defaultCenter] removeObserver:self];
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation
{
    return YES;
}

- (void)updateInputViewFrame {
    CGRect screenFrame = [[UIScreen mainScreen] applicationFrame];
    UIInterfaceOrientation orientation = [[UIApplication sharedApplication] statusBarOrientation];
    
    /* Move the toolbar to above the keyboard */
	[UIView beginAnimations:nil context:NULL];
	[UIView setAnimationDuration:0.3];
	CGRect frame = self.inputToolbar.frame;
    
    if (UIInterfaceOrientationIsPortrait(orientation)) {
        frame.origin.y = screenFrame.size.height - frame.size.height - keyboardHeight;
    }
    else {
        frame.origin.y = screenFrame.size.width - frame.size.height - keyboardHeight;
    }
    
    self.inputToolbar.frame = frame;
}

-(void)willRotateToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation duration:(NSTimeInterval)duration
{
    [self updateInputViewFrame];

    if (UIInterfaceOrientationIsPortrait(toInterfaceOrientation)) {
        [self.inputToolbar.textView setMaximumNumberOfLines:7];
    }
    else {
        [self.inputToolbar.textView setMaximumNumberOfLines:7];
    }    
}

#pragma mark -
#pragma mark Notifications
- (void)keyboardWillShow:(NSNotification *)notification
{
    NSDictionary *userInfo = [notification userInfo];
    CGSize kbSize = [[userInfo objectForKey:UIKeyboardFrameBeginUserInfoKey] CGRectValue].size;
    UIInterfaceOrientation orientation = [[UIApplication sharedApplication] statusBarOrientation];
    
    keyboardHeight = UIInterfaceOrientationIsPortrait(orientation) ? kbSize.height : kbSize.width;
    
    [self updateInputViewFrame];
}

- (void)keyboardWillHide:(NSNotification *)notification 
{
    keyboardHeight = 0;
    
    [self updateInputViewFrame];
}

-(void)inputButtonPressed:(NSString *)inputText
{
    /* Called when toolbar button is pressed */
    NSLog(@"Pressed button with text: '%@'", inputText);
}
@end
