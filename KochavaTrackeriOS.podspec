#
# Be sure to run `pod lib lint KochavaTrackeriOS.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'KochavaTrackeriOS'
  s.version          = '4.3.1'
  s.summary          = 'The KochavaTracker module of the KochavaTracker iOS SDK.'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

s.description  = <<-DESC
The KochavaTracker module is an optional module within the Kochava SDK providing install attribution and analytics.
DESC

  s.homepage         = 'http://www.kochava.com'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'Commercial', :file => 'LICENSE' }
  s.author       = { 'Kochava' => 'support@kochava.com' }
  s.source           = { :git => 'https://github.com/Kochava/kochava-tracker-ios-sdk-cocoapod.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '10.3'

  s.source_files = 'KochavaTrackeriOS/Classes/**/*'
  
  # s.resource_bundles = {
  #   'KochavaTrackeriOS' => ['KochavaTrackeriOS/Assets/*.png']
  # }

  s.public_header_files = 'KochavaTrackeriOS/Classes/**/*.h'
  s.frameworks   = 'Foundation', 'UIKit', 'AVFoundation', 'AdSupport', 'CoreGraphics', 'CoreLocation', 'CoreTelephony', 'iAd', 'SystemConfiguration', 'WebKit'
  s.dependency 'KochavaCoreiOS', '~> 4.3.1'

  s.platform     = :ios, '10.3'
  s.vendored_libraries = 'KochavaTrackeriOS/Libraries/libKochavaCoreiOS.a', 'KochavaTrackeriOS/Libraries/libKochavaTrackeriOS.a'
  s.preserve_paths = 'KochavaTrackeriOS/Libraries/libKochavaCoreiOS.a', 'KochavaTrackeriOS/Libraries/libKochavaTrackeriOS.a'
  # s.library = 'KochavaTrackeriOS'

  s.swift_versions = '5.0'
  
  # Xcode 12 Bug Fix:  https://github.com/CocoaPods/CocoaPods/issues/10065#issuecomment-694268918
  s.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }

end
