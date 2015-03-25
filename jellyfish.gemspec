# coding: utf-8
lib = File.expand_path('../lib', __FILE__)
$LOAD_PATH.unshift(lib) unless $LOAD_PATH.include?(lib)

Gem::Specification.new do |spec|
  spec.name          = "jellyfish"
  spec.version       = "0.1.0"
  spec.authors       = ["gihnius"]
  spec.email         = ["gihnius@gmail.com"]
  spec.summary       = %q{a ruby wrapper for cjellyfish}
  spec.description   = %q{a ruby gem for doing approximate and phonetic matching of strings.}
  spec.homepage      = ""
  spec.license       = "MIT"

  spec.files         = `git ls-files -z`.split("\x0")
  spec.executables   = spec.files.grep(%r{^bin/}) { |f| File.basename(f) }
  spec.test_files    = spec.files.grep(%r{^(test|spec|features)/})
  spec.require_paths = ["lib"]

  spec.add_development_dependency "bundler", "~> 1.9.1"
  spec.add_development_dependency "rake", "~> 10.4.2"

  spec.extensions = %w[ext/cjellyfish/extconf.rb]
end
