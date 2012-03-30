/*
 *  UIExpandingTextView.h
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

#import <UIKit/UIKit.h>
#import "UIExpandingTextViewInternal.h"

@class UIExpandingTextView;

@protocol UIExpandingTextViewDelegate

@optional
- (BOOL)expandingTextViewShouldBeginEditing:(UIExpandingTextView *)expandingTextView;
- (BOOL)expandingTextViewShouldEndEditing:(UIExpandingTextView *)expandingTextView;

- (void)expandingTextViewDidBeginEditing:(UIExpandingTextView *)expandingTextView;
- (void)expandingTextViewDidEndEditing:(UIExpandingTextView *)expandingTextView;

- (BOOL)expandingTextView:(UIExpandingTextView *)expandingTextView shouldChangeTextInRange:(NSRange)range replacementText:(NSString *)text;
- (void)expandingTextViewDidChange:(UIExpandingTextView *)expandingTextView;

- (void)expandingTextView:(UIExpandingTextView *)expandingTextView willChangeHeight:(float)height;
- (void)expandingTextView:(UIExpandingTextView *)expandingTextView didChangeHeight:(float)height;

- (void)expandingTextViewDidChangeSelection:(UIExpandingTextView *)expandingTextView;
- (BOOL)expandingTextViewShouldReturn:(UIExpandingTextView *)expandingTextView;
@end

@interface UIExpandingTextView : UIView <UITextViewDelegate> 
{
    UIExpandingTextViewInternal *internalTextView;
    UIImageView *textViewBackgroundImage;
    int minimumHeight;
	int maximumHeight;
    int maximumNumberOfLines;
	int minimumNumberOfLines;
	BOOL animateHeightChange;
	NSObject <UIExpandingTextViewDelegate> *delegate;
	NSString *text;
	UIFont *font;
	UIColor *textColor;
	UITextAlignment textAlignment; 
	NSRange selectedRange;
	BOOL editable;
	UIDataDetectorTypes dataDetectorTypes;
	UIReturnKeyType returnKeyType;
    BOOL forceSizeUpdate;
    NSString *placeholder;
    UILabel *placeholderLabel;
}

@property (nonatomic, retain) UITextView *internalTextView;

@property int maximumNumberOfLines;
@property int minimumNumberOfLines;
@property BOOL animateHeightChange;

@property (assign) NSObject<UIExpandingTextViewDelegate> *delegate;
@property (nonatomic,assign) NSString *text;
@property (nonatomic,assign) UIFont *font;
@property (nonatomic,assign) UIColor *textColor;
@property (nonatomic) UITextAlignment textAlignment;
@property (nonatomic) NSRange selectedRange;
@property (nonatomic,getter=isEditable) BOOL editable;
@property (nonatomic) UIDataDetectorTypes dataDetectorTypes __OSX_AVAILABLE_STARTING(__MAC_NA, __IPHONE_3_0);
@property (nonatomic) UIReturnKeyType returnKeyType;
@property (nonatomic, retain) UIImageView *textViewBackgroundImage;
@property (nonatomic,copy) NSString *placeholder;
- (BOOL)hasText;
- (void)scrollRangeToVisible:(NSRange)range;
- (void)clearText;

@end
