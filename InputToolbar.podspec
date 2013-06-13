Pod::Spec.new do |s|
  s.name         = "InputToolbar"
  s.version      = "0.0.2"
  s.summary      = "Messages style input toolbar for iOS. Forked from https://github.com/brandonhamilton/inputtoolbar""
  s.homepage     = "https://github.com/chaione/inputtoolbar"
  s.license      = 'MIT'
  s.author       = { "Brandon Hamilton" => "brandon.hamilton@gmail.com" }
  s.source       = {:git => "https://github.com/chaione/inputtoolbar.git"}
  s.platform     = :ios
  s.source_files = 'UIInputToolbarSample/Classes/UIInputToolbar'
  s.resources    = "UIInputToolbarSample/Resources/*.png"
end
