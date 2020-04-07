#
# Be sure to run `pod lib lint KochavaTrackeriOS.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'KochavaTrackeriOS'
  s.version          = '3.16.0'
  s.summary          = 'The KochavaTracker iOS SDK.  Kochava is a leading mobile attribution and analytics platform.'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

s.description  = <<-DESC
A lightweight and easy to integrate SDK written in Objective-C, providing first-class integration with Kochava’s installation attribution and analytics platform.
DESC

  s.homepage         = 'http://www.kochava.com'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'Commercial', :file => 'LICENSE' }
  s.author       = { 'Kochava' => 'support@kochava.com' }
  s.source           = { :git => 'https://github.com/Kochava/kochava-tracker-ios-sdk-cocoapod.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '8.0'

  s.source_files = 'KochavaTrackeriOS/Classes/**/*'
  
  # s.resource_bundles = {
  #   'KochavaTrackeriOS' => ['KochavaTrackeriOS/Assets/*.png']
  # }

  s.public_header_files = 'KochavaTrackeriOS/Classes/**/*.h'
  s.frameworks   = 'Foundation', 'UIKit', 'AVFoundation', 'AdSupport', 'CoreGraphics', 'CoreLocation', 'CoreTelephony', 'iAd', 'SystemConfiguration', 'WebKit'
  s.dependency 'KochavaCoreiOS', '~> 3.16'

  s.platform     = :ios, '8.0'
  s.vendored_libraries = 'KochavaTrackeriOS/Libraries/libKochavaCoreiOS.a', 'KochavaTrackeriOS/Libraries/libKochavaTrackeriOS.a'
  s.preserve_paths = 'KochavaTrackeriOS/Libraries/libKochavaCoreiOS.a', 'KochavaTrackeriOS/Libraries/libKochavaTrackeriOS.a'
  s.library = 'KochavaTrackeriOS'

  s.swift_versions = '5.0'
end
