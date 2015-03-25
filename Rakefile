require "bundler/gem_tasks"
require 'rake/extensiontask'

GEMSPEC = Gem::Specification.load(File.expand_path("../jellyfish.gemspec", __FILE__))

Rake::ExtensionTask.new('cjellyfish', GEMSPEC) do |ext|
  ext.name    = 'jellyfish'
  ext.lib_dir = 'lib/jellyfish'
end
